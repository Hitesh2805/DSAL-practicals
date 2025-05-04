#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name, division, address;
};

void addStudent(const Student& s) {
    ofstream out("students.txt", ios::app);
    out << s.roll << " " << s.name << " " << s.division << " " << s.address << endl;
}

void deleteStudent(int roll) {
    ifstream in("students.txt");
    ofstream out("temp.txt");
    Student s;
    bool found = false;

    while (in >> s.roll >> s.name >> s.division >> s.address) {
        if (s.roll == roll) {
            found = true;
        } else {
            out << s.roll << " " << s.name << " " << s.division << " " << s.address << endl;
        }
    }

    in.close();
    out.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) cout << "Student deleted." << endl;
    else cout << "Student not found!" << endl;
}

void displayStudent(int roll) {
    ifstream in("students.txt");
    Student s;
    bool found = false;

    while (in >> s.roll >> s.name >> s.division >> s.address) {
        if (s.roll == roll) {
            found = true;
            cout << "Roll: " << s.roll << ", Name: " << s.name << ", Division: " << s.division << ", Address: " << s.address << endl;
            break;
        }
    }

    in.close();
    if (!found) cout << "Student not found!" << endl;
}

int main() {
    int choice, roll;
    string name, division, address;

    while (true) {
        cout << "1. Add Student\n2. Delete Student\n3. Display Student\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter roll number: "; cin >> roll;
            cin.ignore();
            cout << "Enter name: "; getline(cin, name);
            cout << "Enter division: "; getline(cin, division);
            cout << "Enter address: "; getline(cin, address);
            addStudent({roll, name, division, address});
        }
        else if (choice == 2) {
            cout << "Enter roll number to delete: "; cin >> roll;
            deleteStudent(roll);
        }
        else if (choice == 3) {
            cout << "Enter roll number to display: "; cin >> roll;
            displayStudent(roll);
        }
        else if (choice == 4) break;
    }

    return 0;
}



