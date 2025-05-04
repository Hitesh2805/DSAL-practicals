#include <iostream>
using namespace std;

struct Node {
    int key, value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(0) {}
};

class Dict {
    Node* table[10];
    int hash(int k) { return k % 10; }

public:
    Dict() {
        for (int i = 0; i < 10; i++) table[i] = 0;
    }

    void insert(int k, int v) {
        int i = hash(k);
        Node* p = table[i];
        while (p) {
            if (p->key == k) { p->value = v; return; }
            p = p->next;
        }
        Node* n = new Node(k, v);
        n->next = table[i];
        table[i] = n;
    }

    void find(int k) {
        int i = hash(k);
        Node* p = table[i];
        while (p) {
            if (p->key == k) { cout << "Found: " << p->value << "\n"; return; }
            p = p->next;
        }
        cout << "Not found\n";
    }

    void del(int k) {
        int i = hash(k);
        Node *p = table[i], *prev = 0;
        while (p) {
            if (p->key == k) {
                if (prev) prev->next = p->next;
                else table[i] = p->next;
                delete p;
                cout << "Deleted\n";
                return;
            }
            prev = p; p = p->next;
        }
        cout << "Not found\n";
    }

    void show() {
        for (int i = 0; i < 10; i++) {
            cout << i << ": ";
            Node* p = table[i];
            while (p) {
                cout << "(" << p->key << "," << p->value << ") ";
                p = p->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    Dict d; int ch, k, v;
    do {
        cout << "\n1.Insert 2.Find 3.Delete 4.Show 5.Exit: ";
        cin >> ch;
        if (ch == 1) { cout << "Key & Value: "; cin >> k >> v; d.insert(k, v); }
        else if (ch == 2) { cout << "Key: "; cin >> k; d.find(k); }
        else if (ch == 3) { cout << "Key: "; cin >> k; d.del(k); }
        else if (ch == 4) d.show();
    } while (ch != 5);
}

// OUTPUT


1.Insert 2.Find 3.Delete 4.Show 5.Exit: 1
Key & Value: 1 45

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 1
Key & Value: 2 55

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 1
Key & Value: 3 67

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 1
Key & Value: 4 65

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 4
0: 
1: (1,45) 
2: (2,55) 
3: (3,67) 
4: (4,65) 
5: 
6: 
7: 
8: 
9: 

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 2
Key: 4
Found: 65

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 3
Key: 3
Deleted

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 4
0: 
1: (1,45) 
2: (2,55) 
3: 
4: (4,65) 
5: 
6: 
7: 
8: 
9: 

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 5
