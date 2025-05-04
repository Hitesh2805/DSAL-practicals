#include <iostream>
#include <vector>
using namespace std;

struct Entry {
    string name, phone;
    bool deleted = false, empty = true;
};

class HashTable {
    vector<Entry> table;
    int size = 101;
    int comparisons;

    int hash(string key) {
        int h = 0;
        for (char c : key) h = (h * 31 + c) % size;
        return h;
    }

    int probe(string key, int i) {
        return (hash(key) + i + i*i) % size;
    }

public:
    HashTable() { table.resize(size); }

    void insert(string name, string phone) {
        for (int i = 0; i < size; i++) {
            int idx = probe(name, i);
            if (table[idx].empty || table[idx].deleted) {
                table[idx] = {name, phone, false, false};
                cout << "Added " << name << endl;
                return;
            }
            if (table[idx].name == name && !table[idx].deleted) {
                cout << name << " already exists\n";
                return;
            }
        }
        cout << "Table full\n";
    }

    void search(string name) {
        comparisons = 0;
        for (int i = 0; i < size; i++) {
            int idx = probe(name, i);
            comparisons++;
            if (table[idx].empty) break;
            if (!table[idx].deleted && table[idx].name == name) {
                cout << "Found: " << name << " - " << table[idx].phone 
                     << " (" << comparisons << " comparisons)\n";
                return;
            }
        }
        cout << name << " not found (" << comparisons << " comparisons)\n";
    }

    void remove(string name) {
        for (int i = 0; i < size; i++) {
            int idx = probe(name, i);
            if (table[idx].empty) break;
            if (!table[idx].deleted && table[idx].name == name) {
                table[idx].deleted = true;
                cout << "Removed " << name << endl;
                return;
            }
        }
        cout << name << " not found\n";
    }

    void display() {
        cout << "\nDirectory:\n";
        for (auto &e : table)
            if (!e.empty && !e.deleted)
                cout << e.name << ": " << e.phone << endl;
    }
};

int main() {
    HashTable dir;
    while (true) {
        cout << "\n1. Add 2. Search 3. Remove 4. Display 5. Exit\nChoice: ";
        int c; cin >> c; cin.ignore();
        string name, phone;
        switch (c) {
            case 1: cout << "Name: "; getline(cin, name);
                    cout << "Phone: "; getline(cin, phone);
                    dir.insert(name, phone); break;
            case 2: cout << "Name: "; getline(cin, name);
                    dir.search(name); break;
            case 3: cout << "Name: "; getline(cin, name);
                    dir.remove(name); break;
            case 4: dir.display(); break;
            case 5: return 0;
            default: cout << "Invalid\n";
        }
    }
}

// OUTPUT


1. Add 2. Search 3. Remove 4. Display 5. Exit
Choice: 1
Name: TEJAS
Phone: 5671238975
Added TEJAS

1. Add 2. Search 3. Remove 4. Display 5. Exit
Choice: 1
Name: DARSHAN
Phone: 6592645937
Added DARSHAN

1. Add 2. Search 3. Remove 4. Display 5. Exit
Choice: 4

Directory:
TEJAS: 5671238975
DARSHAN: 6592645937

1. Add 2. Search 3. Remove 4. Display 5. Exit
Choice: 2
Name: TEJAS
Found: TEJAS - 5671238975 (1 comparisons)

1. Add 2. Search 3. Remove 4. Display 5. Exit
Choice: 3
Name: DARSHAN
Removed DARSHAN

1. Add 2. Search 3. Remove 4. Display 5. Exit
Choice: 4

Directory:
TEJAS: 5671238975

1. Add 2. Search 3. Remove 4. Display 5. Exit
Choice: 5
