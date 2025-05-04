#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val) {}
};

Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

int findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root ? root->data : -1;
}

int longestPath(Node* root) {
    if (!root) return 0;
    return max(longestPath(root->left), longestPath(root->right)) + 1;
}

int main() {
    Node* root = nullptr;
    int n, value;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter the nodes: ";
    while (n--) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Enter new value to insert: ";
    cin >> value;
    root = insert(root, value);

    cout << "Longest path from root: " << longestPath(root) << endl;
    cout << "Minimum value in the tree: " << findMin(root) << endl;

    return 0;
}

// OUTPUT
Enter number of nodes: 5
Enter the nodes: 20 8 25 4 12
Enter new value to insert: 10
Longest path from root: 4
Minimum value in the tree: 4
