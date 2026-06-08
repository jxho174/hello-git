#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    int date_joined, month_joined, year_joined;
    int date_birth, month_birth, year_birth;

public:
    Employee(string a_name = "", int a_id = 0, int a_date_joined = 1, int a_month_joined = 1, int a_year_joined = 1999, int a_date_birth = 1, int a_month_birth = 1, int a_year_birth = 1999) {
        name = a_name;
        id = a_id;
        date_joined = a_date_joined;
        month_joined = a_month_joined;
        year_joined = a_year_joined;
        date_birth = a_date_birth;
        month_birth = a_month_birth;
        year_birth = a_year_birth;
    }

    void employeeInfoInput() {
        cout << "Enter employee name: ";
        getline(cin, name);
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter date joined (DD MM YYYY): ";
        cin >> date_joined >> month_joined >> year_joined;
        cout << "Enter date of birth (DD MM YYYY): ";
        cin >> date_birth >> month_birth >> year_birth;
    }

    // THE ENCODER
    void saveToFile(string filename) {
        ofstream file(filename, ios::out | ios::binary);
        if (file.is_open()) {
            cout << "Saving employee data to file..." << endl;
            
            // 1. SAVE THE STRING
            size_t nameLength = name.size();
            file.write((char*)&nameLength, sizeof(nameLength)); // Write length
            file.write(name.data(), nameLength);                // Write characters

            // 2. SAVE THE INTEGERS (Your original code was perfect for ints!)
            file.write((char*)&id, sizeof(id));
            file.write((char*)&date_joined, sizeof(date_joined));
            file.write((char*)&month_joined, sizeof(month_joined));
            file.write((char*)&year_joined, sizeof(year_joined));
            file.write((char*)&date_birth, sizeof(date_birth));
            file.write((char*)&month_birth, sizeof(month_birth));
            file.write((char*)&year_birth, sizeof(year_birth));
            
            file.close();
        } else {
            cerr << "Unable to open file for writing." << endl;
        }
    }

    // THE DECODER
    void readFromFile(string filename) {
        ifstream file(filename, ios::in | ios::binary);
        if (file.is_open()) {
            cout << "Reading employee data from file..." << endl;
            
            // 1. LOAD THE STRING
            size_t nameLength;
            file.read((char*)&nameLength, sizeof(nameLength)); // Read length first
            name.resize(nameLength);                           // Make the string big enough
            file.read(&name[0], nameLength);                   // Read characters into string

            // 2. LOAD THE INTEGERS
            file.read((char*)&id, sizeof(id));
            file.read((char*)&date_joined, sizeof(date_joined));
            file.read((char*)&month_joined, sizeof(month_joined));
            file.read((char*)&year_joined, sizeof(year_joined));
            file.read((char*)&date_birth, sizeof(date_birth));
            file.read((char*)&month_birth, sizeof(month_birth));
            file.read((char*)&year_birth, sizeof(year_birth));
            
            file.close();
        } else {
            cerr << "Unable to open file for reading." << endl;
        }
    }

    // Added a display function to prove it works!
    void display() const {
        cout << "\n--- Loaded Employee Data ---\n";
        cout << "Name: " << name << "\nID: " << id << endl;
        cout << "Joined: " << date_joined << "/" << month_joined << "/" << year_joined << endl;
        cout << "DOB: " << date_birth << "/" << month_birth << "/" << year_birth << endl;
    }
};

int main()
{
    Employee emp;
    emp.employeeInfoInput(); 
    emp.saveToFile("employee.dat"); 
    
    Employee empFromFile; 
    empFromFile.readFromFile("employee.dat"); 
    
    // Prove that the decoder worked!
    empFromFile.display(); 
    
    return 0;
}