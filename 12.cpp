#include <iostream>
using namespace std;

struct Entry {
    int key, value;
    bool isOccupied = false, isDeleted = false;
};

class Dict {
    Entry table[10];  // fixed size hash table
    int hash(int k) { return k % 10; }

public:
    void insert(int k, int v) {
        int i = hash(k);
        if (!table[i].isOccupied || table[i].isDeleted) {
            table[i] = {k, v, true, false};
            return;
        }
        int origIndex = hash(table[i].key);
        if (origIndex != i) { // Replace and reinsert old
            Entry temp = table[i];
            table[i] = {k, v, true, false};
            k = temp.key;
            v = temp.value;
        }
        int j = (i + 1) % 10;
        while (table[j].isOccupied && !table[j].isDeleted)
            j = (j + 1) % 10;
        table[j] = {k, v, true, false};
    }

    void find(int k) {
        int i = hash(k), start = i;
        while (table[i].isOccupied) {
            if (!table[i].isDeleted && table[i].key == k) {
                cout << "Found: " << table[i].value << "\n";
                return;
            }
            i = (i + 1) % 10;
            if (i == start) break;
        }
        cout << "Not found\n";
    }

    void del(int k) {
        int i = hash(k), start = i;
        while (table[i].isOccupied) {
            if (!table[i].isDeleted && table[i].key == k) {
                table[i].isDeleted = true;
                cout << "Deleted\n";
                return;
            }
            i = (i + 1) % 10;
            if (i == start) break;
        }
        cout << "Not found\n";
    }

    void show() {
        for (int i = 0; i < 10; i++) {
            if (table[i].isOccupied && !table[i].isDeleted)
                cout << i << ": " << table[i].key << "->" << table[i].value << "\n";
            else
                cout << i << ": ---\n";
        }
    }
};

int main() {
    Dict d;
    int ch, k, v;
    do {
        cout << "\n1.Insert 2.Find 3.Delete 4.Show 5.Exit: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Key & Value: "; cin >> k >> v;
            d.insert(k, v);
        } else if (ch == 2) {
            cout << "Key: "; cin >> k;
            d.find(k);
        } else if (ch == 3) {
            cout << "Key: "; cin >> k;
            d.del(k);
        } else if (ch == 4) d.show();
    } while (ch != 5);
    return 0;
}

// OUTPUT

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 1
Key & Value: 1 22

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 1
Key & Value: 3 45

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 4
0: ---
1: 1->22
2: ---
3: 3->45
4: ---
5: ---
6: ---
7: ---
8: ---
9: ---

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 2
Key: 3
Found: 45

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 5
