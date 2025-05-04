#include <iostream>
using namespace std;

struct Entry {
    int key, value;
    bool isOccupied = false, isDeleted = false;
};

class Dictionary {
    Entry table[10];  // Fixed size
    int hash(int k) { return k % 10; }

public:
    void insert(int k, int v) {
        int i = hash(k);
        for (int j = 0; j < 10; j++) {
            int idx = (i + j) % 10;
            if (!table[idx].isOccupied || table[idx].isDeleted) {
                table[idx] = {k, v, true, false};
                return;
            }
        }
        cout << "Table full\n";
    }

    void find(int k) {
        int i = hash(k);
        for (int j = 0; j < 10; j++) {
            int idx = (i + j) % 10;
            if (table[idx].isOccupied && !table[idx].isDeleted && table[idx].key == k) {
                cout << "Found: " << table[idx].value << "\n";
                return;
            }
        }
        cout << "Not found\n";
    }

    void del(int k) {
        int i = hash(k);
        for (int j = 0; j < 10; j++) {
            int idx = (i + j) % 10;
            if (table[idx].isOccupied && !table[idx].isDeleted && table[idx].key == k) {
                table[idx].isDeleted = true;
                cout << "Deleted\n";
                return;
            }
        }
        cout << "Not found\n";
    }

    void show() {
        for (int i = 0; i < 10; i++) {
            if (table[i].isOccupied && !table[i].isDeleted)
                cout << i << ": " << table[i].key << " => " << table[i].value << "\n";
            else
                cout << i << ": ---\n";
        }
    }
};

int main() {
    Dictionary d;
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
        } else if (ch == 4) {
            d.show();
        }
    } while (ch != 5);
    return 0;
}

// OUTPUT


1.Insert 2.Find 3.Delete 4.Show 5.Exit: 1
Key & Value: 1 34

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 1
Key & Value: 2 33

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 1
Key & Value: 3 43

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 4
0: ---
1: 1 => 34
2: 2 => 33
3: 3 => 43
4: ---
5: ---
6: ---
7: ---
8: ---
9: ---

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 2
Key: 2
Found: 33

1.Insert 2.Find 3.Delete 4.Show 5.Exit: 5
