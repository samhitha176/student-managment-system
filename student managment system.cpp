#include <iostream>
#include <vector>
#include <string>
using namespace std;

// -------------------- Classes --------------------

class Student {
    int id;
    string name;
    int age;
    string department;

public:
    void setDetails(int sid, const string& sname, int sage, const string& dept) {
        id = sid;
        name = sname;
        age = sage;
        department = dept;
    }

    int getID() const { return id; }
    string getName() const { return name; }

    void updateDetails() {
        cout << "Updating details for Student ID " << id << endl;
        cout << "Enter new name: "; cin.ignore(); getline(cin, name);
        cout << "Enter new age: "; cin >> age;
        cin.ignore();
        cout << "Enter new department: "; getline(cin, department);
        cout << "Details updated successfully!\n";
    }

    void display() const {
        cout << "ID: " << id 
             << ", Name: " << name 
             << ", Age: " << age 
             << ", Department: " << department << endl;
    }
};

// -------------------- Management System --------------------

class StudentManagementSystem {
    vector<Student> students;
    int nextID = 1;

public:
    void addStudent() {
        string name, department;
        int age;

        cout << "Enter Student Name: ";
        cin.ignore(); getline(cin, name);
        cout << "Enter Age: "; cin >> age;
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, department);

        Student s;
        s.setDetails(nextID++, name, age, department);
        students.push_back(s);

        cout << "Student added successfully!\n";
    }

    void updateStudent() {
        int sid;
        cout << "Enter Student ID to update: "; cin >> sid;
        for (auto &s : students) {
            if (s.getID() == sid) {
                s.updateDetails();
                return;
            }
        }
        cout << "Student with ID " << sid << " not found!\n";
    }

    void searchStudent() {
        string name;
        cout << "Enter Student Name to search: ";
        cin.ignore(); getline(cin, name);
        bool found = false;

        for (const auto &s : students) {
            if (s.getName() == name) {
                s.display();
                found = true;
            }
        }

        if (!found) cout << "No student found with name: " << name << endl;
    }

    void displayAll() const {
        cout << "\n--- All Students ---\n";
        for (const auto &s : students) {
            s.display();
        }
    }
};

// -------------------- Main --------------------

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n2. Update Student\n3. Search Student\n4. Display All Students\n0. Exit\n";
        cout << "Enter your choice: "; cin >> choice;

        switch(choice) {
            case 1: sms.addStudent(); break;
            case 2: sms.updateStudent(); break;
            case 3: sms.searchStudent(); break;
            case 4: sms.displayAll(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}

