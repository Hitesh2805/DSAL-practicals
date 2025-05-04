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
    bool search(node*, int); 
    void mirror(node *);
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

bool Bst::search(node *root, int n) {
    node *temp = root;
    while (temp != NULL) {
        if (n == temp->data) {
            return true;
        } else if (n < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}

void Bst::mirror(node *root) {
    if (root == NULL) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

int main() {
    Bst o;
    int choice;
    char ch;
    do {
        cout << "\n1. Insert\n2. Display\n3. Search\n4. Mirror\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                o.create();
                break;
            case 2:
                o.dis();
                break;
            case 3: {
                int key;
                cout << "Enter the node to search: ";
                cin >> key;
                if (o.search(o.root, key)) {
                    cout << "Node found.\n";
                } else {
                    cout << "Node not found.\n";
                }
                break;
            }
            case 4:
                o.mirror(o.root);
                cout << "Tree mirrored successfully.\n";
                o.dis();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        cout << "Do you want to continue (y/n)? ";
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
