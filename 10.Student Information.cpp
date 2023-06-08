/*10.Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. 
Display information of particular employee. If record of student does not exist an appropriate message is displayed. If it is, then the system displays the 
student details*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};
void addStudent() {
    ofstream file("student.txt", ios::app);
    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Enter Division: ";
    getline(cin, student.division);

    cout << "Enter Address: ";
    getline(cin, student.address);

    file << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << endl;

    file.close();

    cout << "Student record added successfully!" << endl;
}
void deleteStudent() {
    int rollNumber;
    cout << "Enter Roll Number to delete: ";
    cin >> rollNumber;

    ifstream inputFile("student.txt");
    ofstream tempFile("temp.txt");

    bool recordFound = false;
    string line;
    while (getline(inputFile, line)) 
	{
        int storedRollNumber = stoi(line.substr(0, line.find(',')));
        if (storedRollNumber == rollNumber) {
            recordFound = true;
            continue;
        }
        tempFile << line << endl;
    }

    inputFile.close();
    tempFile.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (recordFound) {
        cout << "Student record deleted successfully!" << endl;
    } else {
        cout << "Student record not found!" << endl;
    }
}
void displayStudent() {
    int rollNumber;
    cout << "Enter Roll Number to display: ";
    cin >> rollNumber;

    ifstream file("student.txt");
    string line;
    bool recordFound = false;
    while (getline(file, line)) {
        int storedRollNumber = stoi(line.substr(0, line.find(',')));
        if (storedRollNumber == rollNumber) {
            recordFound = true;
            cout << "Student Details:" << endl;
            cout << line << endl;
            break;
        }
    }
    file.close();

    if (!recordFound) {
        cout << "Student record not found!" << endl;
    }
}
int main() {
    int choice;

    do {
        cout << "---------- Student Information Management System ----------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student Information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
        cout << endl;
    } while (choice != 4);
    return 0;
}
