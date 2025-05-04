#include <iostream>
using namespace std;

struct Node {
    string key, meaning;
    Node *l, *r; int h;
    Node(string k, string m) : key(k), meaning(m), l(0), r(0), h(1) {}
};

int height(Node* n) {
    return n ? n->h : 0;
}

int balance(Node* n) {
    return height(n->l) - height(n->r);
}

Node* rotateR(Node* y) {
    Node* x = y->l;
    y->l = x->r; x->r = y;
    y->h = max(height(y->l), height(y->r)) + 1;
    x->h = max(height(x->l), height(x->r)) + 1;
    return x;
}

Node* rotateL(Node* x) {
    Node* y = x->r;
    x->r = y->l; y->l = x;
    x->h = max(height(x->l), height(x->r)) + 1;
    y->h = max(height(y->l), height(y->r)) + 1;
    return y;
}

Node* insert(Node* n, string k, string m) {
    if (!n) return new Node(k, m);
    if (k < n->key) n->l = insert(n->l, k, m);
    else if (k > n->key) n->r = insert(n->r, k, m);
    else return n;

    n->h = 1 + max(height(n->l), height(n->r));
    int b = balance(n);

    if (b > 1 && k < n->l->key) return rotateR(n);
    if (b < -1 && k > n->r->key) return rotateL(n);
    if (b > 1 && k > n->l->key) { n->l = rotateL(n->l); return rotateR(n); }
    if (b < -1 && k < n->r->key) { n->r = rotateR(n->r); return rotateL(n); }

    return n;
}

Node* minNode(Node* n) {
    while (n->l) n = n->l;
    return n;
}

Node* del(Node* r, string k) {
    if (!r) return 0;
    if (k < r->key) r->l = del(r->l, k);
    else if (k > r->key) r->r = del(r->r, k);
    else {
        if (!r->l || !r->r) {
            Node* temp = r->l ? r->l : r->r;
            if (!temp) return 0;
            *r = *temp;
        } else {
            Node* temp = minNode(r->r);
            r->key = temp->key;
            r->meaning = temp->meaning;
            r->r = del(r->r, temp->key);
        }
    }

    r->h = 1 + max(height(r->l), height(r->r));
    int b = balance(r);
    if (b > 1 && balance(r->l) >= 0) return rotateR(r);
    if (b > 1 && balance(r->l) < 0) { r->l = rotateL(r->l); return rotateR(r); }
    if (b < -1 && balance(r->r) <= 0) return rotateL(r);
    if (b < -1 && balance(r->r) > 0) { r->r = rotateR(r->r); return rotateL(r); }

    return r;
}

void display(Node* r, bool asc) {
    if (!r) return;
    if (asc) { display(r->l, asc); cout << r->key << ": " << r->meaning << "\n"; display(r->r, asc); }
    else     { display(r->r, asc); cout << r->key << ": " << r->meaning << "\n"; display(r->l, asc); }
}

int search(Node* r, string k, int cmp = 1) {
    if (!r) return cmp - 1;
    if (r->key == k) return cmp;
    return k < r->key ? search(r->l, k, cmp + 1) : search(r->r, k, cmp + 1);
}

int main() {
    Node* root = 0;
    int ch; string k, m;
    do {
        cout << "\n1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: ";
        cin >> ch;
        if (ch == 1) { cin >> k >> m; root = insert(root, k, m); }
        if (ch == 2) { cin >> k; root = del(root, k); }
        if (ch == 3) display(root, 1);
        if (ch == 4) display(root, 0);
        if (ch == 5) { cin >> k; cout << "Comparisons: " << search(root, k) << "\n"; }
    } while (ch);
}

// OUPUT


1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 1
1 APPLE

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 1
2 BANANA

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 1
3 STRAWBERRY

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 1
4
MANGO

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 3
1: APPLE
2: BANANA
3: STRAWBERRY
4: MANGO

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 4
4: MANGO
3: STRAWBERRY
2: BANANA
1: APPLE

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 5
1
Comparisons: 2

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 5
3
Comparisons: 2

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 5
2
Comparisons: 1

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 5
APPLE
Comparisons: 3

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 5
BANANA
Comparisons: 3

1.Insert 2.Delete 3.DisplayAsc 4.DisplayDesc 5.Search 0.Exit: 0
