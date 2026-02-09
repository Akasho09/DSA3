## A Tree 
- is a non-linear data structure used to store hierarchical data. Unlike arrays or linked lists (linear structures), trees organize data in parent-child relationships.
- A Tree is a special type of graph that:
    - Has a hierarchical structure
    - Has exactly one root node
    - Contains no cycles
    - Has N nodes → N-1 edges

### 📌 Basic Terminology
- Node → Basic element of a tree
- Root → Topmost node
- Parent → Node that has children
- Child → Node derived from another node
- Leaf Node → Node with no children
- Height → Maximum number of edges from root to leaf
- Subtree → Tree formed from a node and its children

### 📌 Types of Trees in Programming
1. Binary Tree – Each node has at most 2 children
2. Binary Search Tree (BST) – Left child < Parent < Right child
3. AVL Tree – Self-balancing BST
4. Heap – Complete binary tree used in priority queues
5. Trie – Used for strings and prefix searching

```c
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    return 0;
}

       1
      / \
     2   3
    /
   4
```

## 🌲 Tree Traversal Techniques
- Traversal means visiting every node in a tree.

1. ✅ 1. Inorder Traversal (Left → Root → Right)
```c
void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
```

2. ✅ 2. Preorder Traversal (Root → Left → Right)
```c
void preorder(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
```

3. ✅ 3. Postorder Traversal (Left → Right → Root)
```c
void postorder(Node* root) {
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
```

### 🌲 Binary Search Tree (BST) in C++
- BST follows ordering rules:
    - 👉 Left subtree contains smaller values
    - 👉 Right subtree contains greater values
- ✅ Insert in BST
```c
Node* insert(Node* root, int value) {

    if(root == NULL)
        return new Node(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}
```
- ✅ Searching in BST
```c
bool search(Node* root, int key) {

    if(root == NULL) return false;

    if(root->data == key)
        return true;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
```
### 🌟 Time Complexity
| Operation | BST Average | BST Worst |
| --------- | ----------- | --------- |
| Insert    | O(log n)    | O(n)      |
| Search    | O(log n)    | O(n)      |
| Delete    | O(log n)    | O(n)      |


## 🕸️ What is a Graph?
- A graph is a data structure made of:
    - Vertices (Nodes) → Points
    - Edges → Connections between nodes
- Graphs represent relationships between objects.

### ✅ Types of Graphs
1. Undirected Graph
- Connection works both ways
2. Directed Graph
- Connection has direction (→)
3. Weighted Graph
- Connections have cost or distance

| Feature             | 🌳 Tree                              | 🌐 Graph                         |
| ------------------- | ------------------------------------ | -------------------------------- |
| Structure           | Hierarchical                         | Network / Non-hierarchical       |
| Root Node           | Always present                       | Not required                     |
| Cycles              | Not allowed                          | Allowed                          |
| Number of Edges     | N - 1                                | Any number                       |
| Connectivity        | Always connected                     | May or may not be connected      |
| Parent Relationship | Each child has one parent            | Node can have multiple parents   |
| Traversal           | DFS, BFS (structured)                | DFS, BFS (complex due to cycles) |
| Direction           | Usually directional (parent → child) | Can be directed or undirected    |
| Complexity          | Simpler                              | More complex                     |
