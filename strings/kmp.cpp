#include <iostream>
using namespace std;

// Build LPS array
vector<int> buildLPS(string pattern) {
    int n = pattern.size();
    vector<int>lps(n ,  0);
    int len = 0;
    for(int i=1;i<n;i++){
        if(pattern[i]==pattern[len]){
            lps[i]=++len;
        }else if(len>0){
             len = lps[len - 1];
        }
    }
    for(int i=0;i<n;i++) cout <<lps[i] <<" " ;
    return lps;
}

// KMP Search
bool KMPSearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    if (m == 0) return true;
    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) return true; // found pattern
        } else if (j > 0) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    return false;
}

int main() {
    string text = "ababcababcababc";
    string pattern = "ababc";
    cout << (KMPSearch(text, pattern) ? "Found" : "Not found") << endl;
}
