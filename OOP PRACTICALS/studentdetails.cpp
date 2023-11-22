#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    static int count;
    string name;
    int rollNumber;
    string studentClass;
    string division;
    string dob;
    string bloodGroup;
    string contactAddress;
    long long int telephoneNumber;

public:
    void setDetails(string n, int roll, string sClass, string div,
                    string dob, string blood, string address, long long int phone)
    {
        name = n;
        rollNumber = roll;
        studentClass = sClass;
        division = div;
        this->dob = dob;
        bloodGroup = blood;
        contactAddress = address;
        telephoneNumber = phone;
        count++;
    }

    void displayDetails() {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nClass: " << studentClass
             << "\nDivision: " << division << "\nDate of Birth: " << dob << "\nBlood Group: "
             << bloodGroup << "\nContact Address: " << contactAddress << "\nTelephone Number: " << telephoneNumber
             << endl;
    }

    static int getCount() {
        return count;
    }

    static inline void displayCount() {
        cout << "Total number of students: " << count << endl;
    }
};

int Student::count = 0;

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore(); // consume newline

    Student students[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        string name, sClass, division, dob, blood, address;
        int roll;
        long long int phone;

        cout << "\nEnter details for student " << i + 1 << ":\n";

        cout << "Enter student's name: ";
        getline(cin, name);

        cout << "Enter student's roll number: ";
        cin >> roll;
        cin.ignore(); // consume newline

        cout << "Enter student's class: ";
        getline(cin, sClass);

        cout << "Enter student's division: ";
        getline(cin, division);

        cout << "Enter student's date of birth (YYYY-MM-DD): ";
        getline(cin, dob);

        cout << "Enter student's blood group: ";
        getline(cin, blood);

        cout << "Enter student's contact address: ";
        getline(cin, address);

        cout << "Enter student's telephone number: ";
        cin >> phone;
        cin.ignore(); // consume newline

        students[i].setDetails(name, roll, sClass, division, dob, blood, address, phone);
    }

    cout << "\nDetails of all students:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].displayDetails();
    }

    Student::displayCount();

    return 0;
}
