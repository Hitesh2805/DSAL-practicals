#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

class Bst {
public:
    node *root;
    Bst() {
        root = NULL;
    }

    void create();
    void insert(node*, node*);
    void dis();
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    int height(node *);
    void minval(node *);
};

void Bst::create() {
    char ch;
    do {
        node *nn = new node;
        cout << "Enter data for node: ";
        cin >> nn->data;
        nn->left = NULL;
        nn->right = NULL;
        if (root == NULL) {
            root = nn;
        } else {
            insert(root, nn);
        }
        cout << "Do you want to add more nodes (y/n)? ";
        cin >> ch;
    } while (ch == 'y');
}

void Bst::insert(node *root, node *nn) {
    if (nn->data < root->data) {
        if (root->left == NULL) {
            root->left = nn;
        } else {
            insert(root->left, nn);
        }
    } else {
        if (root->right == NULL) {
            root->right = nn;
        } else {
            insert(root->right, nn);
        }
    }
}

void Bst::inorder(node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void Bst::preorder(node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void Bst::postorder(node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void Bst::dis() {
    cout << "Inorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << endl;
}

int Bst::height(node *root) {
    if (root == NULL) return 0;
    int hl = height(root->left);
    int hr = height(root->right);
    return (hl > hr ? hl : hr) + 1;
}

void Bst::minval(node* root) {
    node *temp = root;
    while (temp && temp->left != NULL) {
        temp = temp->left;
    }
    if (temp) {
        cout << "Min value in the BST is: " << temp->data << endl;
    }
}

int main() {
    Bst o;
    int choice;
    char ch;
    do {
        cout << "1. Insert\n2. Display\n3. Height\n4. Find Min\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                o.create();
                break;
            case 2:
                o.dis();
                break;
            case 3:
                cout << "Height of the BST is: " << o.height(o.root) << endl;
                break;
            case 4:
                o.minval(o.root);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << "Do you want to continue (y/n)? ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
