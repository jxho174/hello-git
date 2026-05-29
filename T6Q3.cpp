#include <iostream>
#include <fstream>
using namespace std;

class Company {
    int numOfStaff;
    Employee* stafflist;

    public:
        

    
};

class Employee {
    private:
        string name;
        double salary;

    public:
        Employee(){
            name = "";
            salary = 0.0;
        }
        Employee(string a_name = "", double a_salary = 0.0)
        : name(a_name), salary(a_salary) {}
        string getName() {return name; }
        void setName(string a_name) { name = a_name; }
        double getSalary() {return salary; }
        void setSalary(double a_salary) { salary = a_salary; }
        void displayStaffInformation() {
            cout << "\nName: " << name << ", Salary = RM " << salary;
        }
        void incrementSalary(float a_rate) {
            if (salary > 2000) {
                cout << endl << name << " not qualified for salary increment." << endl;
                return;
            }
            else{
                salary += salary * a_rate;
            }
        }
};

int main() {
    Employee e1 = Employee("Nurazlan", 1800);
    e1.displayStaffInformation();
    e1.incrementSalary(0.20);
    cout << "\nAfter salary increment";
    e1.displayStaffInformation();
    Employee e2 = Employee("Donald James", 3500);
    e2.incrementSalary(0.20);

    Company astro;
    // cout << "\n\nReading staff name from text file ";
    // astro.getDataFromFile("staff.txt");
    // astro.showAllStaff();
    // cout << endl;
    // cout << "\nReading salary from text file ";
    // astro.getSalaryFromFile("salary.txt");

    cout << "\n\n" ;
    return 0;
}