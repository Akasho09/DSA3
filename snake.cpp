#include <iostream>
#include <unistd.h>    // usleep
#include <termios.h>   // tcgetattr, tcsetattr
#include <fcntl.h>     // fcntl
#include <cstdlib>
#include <ctime>

using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;

int xPos, yPos;
int foodX, foodY;
int score;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

int tailX[100], tailY[100];
int nTail = 0;

static struct termios orig_termios;

// restore terminal mode on exit
void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

// put terminal into raw mode (no buffering, no echo)
void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);      // ensure reset on exit

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO); // no canonical mode, no echo
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

// non-blocking keyboard check
int kbhit() {
    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    int ch = getchar();
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

// read one char (we’re already in raw mode)
char getchNonBlock() {
    return getchar();
}

void Setup() {
    gameOver = false;
    dir = STOP;
    xPos = width / 2;
    yPos = height / 2;
    srand(time(nullptr));
    foodX = rand() % (width - 2) + 1;
    foodY = rand() % (height - 2) + 1;
    score = 0;
    nTail = 0;
}

void Draw() {
    // ANSI escape: clear screen and move cursor to top-left
    cout << "\x1b[2J\x1b[H";

    // top border
    for (int i = 0; i < width + 2; i++) cout << '#';
    cout << '\n';

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << '#';

            if (i == yPos && j == xPos)
                cout << 'O';  // head
            else if (i == foodY && j == foodX)
                cout << 'F';  // food
            else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << 'o';
                        printTail = true;
                        break;
                    }
                }
                if (!printTail) cout << ' ';
            }

            if (j == width - 1) cout << '#';
        }
        cout << '\n';
    }

    // bottom border
    for (int i = 0; i < width + 2; i++) cout << '#';
    cout << "\nScore: " << score << "\nWASD to move, X to exit\n";
}

void Input() {
    if (kbhit()) {
        char c = getchNonBlock();
        switch (c) {
            case 'a': case 'A': dir = LEFT;  break;
            case 'd': case 'D': dir = RIGHT; break;
            case 'w': case 'W': dir = UP;    break;
            case 's': case 'S': dir = DOWN;  break;
            case 'x': case 'X': gameOver = true; break;
            default: break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = xPos;
    tailY[0] = yPos;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:  xPos--; break;
        case RIGHT: xPos++; break;
        case UP:    yPos--; break;
        case DOWN:  yPos++; break;
        default:    break;
    }

    // hit wall
    if (xPos >= width || xPos < 0 || yPos >= height || yPos < 0)
        gameOver = true;

    // hit tail
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == xPos && tailY[i] == yPos)
            gameOver = true;

    // eat food
    if (xPos == foodX && yPos == foodY) {
        score += 10;
        foodX = rand() % (width - 2) + 1;
        foodY = rand() % (height - 2) + 1;
        if (nTail < 100) nTail++;
    }
}

int main() {
    enableRawMode();
    Setup();

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        usleep(120000); // 120 ms
    }

    disableRawMode();
    cout << "Game Over! Final Score: " << score << '\n';
    return 0;
}
