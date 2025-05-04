#include <iostream>
#include <string.h>
#define max 10
using namespace std;

struct node {
    char name[15];
    long int mobno;
    int chain;

    node() {
        strcpy(name, "-");
        mobno = 0;
        chain = -1;
    }
};

class hasht {
    node ht[max];
public:
    hasht() {
        for (int i = 0; i < max; i++) {
            ht[i] = node();
        }
    }

    int hashfun(long int);
    void insert();
    void display();
    void search();
    void del();
};

int hasht::hashfun(long int num) {
    return (num % max);
}

void hasht::insert() {
    int ind, prev;
    node S;
    cout << "Enter name and mobile number of a person:" << endl;
    cin >> S.name >> S.mobno;

    ind = hashfun(S.mobno);
    if (ht[ind].mobno == 0) {
        ht[ind] = S;
    } else {
        prev = ind;
        while (ht[ind].mobno != 0) {
            ind = (ind + 1) % max;
        }
        ht[ind] = S;

        int temp = hashfun(S.mobno);
        while (ht[temp].chain != -1) {
            temp = ht[temp].chain;
        }
        ht[temp].chain = ind;
    }
}

void hasht::display() {
    cout << "Index\tName\t\tMobile Number\tChain" << endl;
    for (int i = 0; i < max; i++) {
        cout << i << "\t" << ht[i].name << "\t\t" << ht[i].mobno << "\t\t" << ht[i].chain << endl;
    }
}

void hasht::search() {
    long int num;
    int ind;
    cout << "Enter the mobile number to search: ";
    cin >> num;

    ind = hashfun(num);
    while (ind != -1) {
        if (num == ht[ind].mobno) {
            cout << "Mobile number found at index: " << ind << endl;
            return;
        }
        ind = ht[ind].chain;
    }
    cout << "Mobile number not found." << endl;
}

void hasht::del() {
    long int num;
    int ind, prev = -1;
    cout << "Enter the mobile number to delete: ";
    cin >> num;

    ind = hashfun(num);
    while (ind != -1) {
        if (num == ht[ind].mobno) {
            if (ht[ind].chain == -1) {
                strcpy(ht[ind].name, "-");
                ht[ind].mobno = 0;
                ht[ind].chain = -1;
            } else {
                int next = ht[ind].chain;
                ht[ind] = ht[next];
                strcpy(ht[next].name, "-");
                ht[next].mobno = 0;
                ht[next].chain = -1;
            }

            if (prev != -1) {
                ht[prev].chain = ht[ind].chain;
            }
            cout << "Record deleted." << endl;
            return;
        }
        prev = ind;
        ind = ht[ind].chain;
    }

    cout << "Mobile number not found." << endl;
}

int main() {
    int choice;
    hasht h;
    char again;

    do {
        cout << "\n1. Insert\n2. Display\n3. Search\n4. Delete\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: h.insert(); break;
            case 2: h.display(); break;
            case 3: h.search(); break;
            case 4: h.del(); break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }

        if (choice != 5) {
            cout << "Do you want to continue? (y/n): ";
            cin >> again;
        } else {
            break;
        }

    } while (again == 'y' || again == 'Y');

    return 0;
}
