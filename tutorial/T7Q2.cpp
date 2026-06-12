#include <iostream>
using namespace std;

class Employee {
    public:
        Employee(string a_name = "", unsigned int a_id = 0, double a_annualSalary = 0.0)
        : name(a_name), id(a_id), annualSalary(a_annualSalary) {}

        void setCompanyName(string a_company) { company = a_company; }

        void setDepartment(string a_department) { department = a_department; }

        string getEmployeeName(void) { return name; }

        unsigned int getEmployeeID(void) { return id; }

        double getAnnualSalary(void) { return annualSalary; }

    protected:
        string name;
        string company;
        string department;
        unsigned int id;
        double annualSalary;
};

class Manager : public Employee {
    private:
        unsigned int numOfExecutives;
        double bonus;

    public:
        Manager(string a_name = "", unsigned int a_id = 0, double a_annualSalary = 0.0) 
        : Employee(a_name, a_id, a_annualSalary) 
        {
            numOfExecutives = 0;
            bonus = 0.0;
        }

        void setNumExecutives(unsigned int num) { numOfExecutives = num; }

        void calculateBonus(void) {
            bonus = annualSalary * (numOfExecutives * 0.15);
            cout << "Manager " << name << " has a bonus of $" << bonus << endl;
        }
};

class Engineer : public Employee {
    private:
        unsigned int numOfTechnician;
        double bonus;

    public:
        Engineer(string a_name = "", unsigned int a_id = 0, double a_annualSalary = 0.0) 
        : Employee(a_name, a_id, a_annualSalary) 
        {
            numOfTechnician = 0;
            bonus = 0.0;
        }

        ~Engineer() {}

        void setNumTechnicians(unsigned int num) { numOfTechnician = num; }

        void calculateBonus(void) {
            bonus = annualSalary * (numOfTechnician * 0.10);
            cout << "Engineer " << name << " has a bonus of $" << bonus << endl;
        }
};

int main()
{
    string companyName = "ABC Company", departmentName = "Engineering";
    Manager m1("John Doe", 12345, 100000.0);
    m1.setCompanyName(companyName);
    m1.setDepartment(departmentName);
    m1.setNumExecutives(3);

    Engineer e1("Jane Smith", 54321, 80000.0);
    e1.setCompanyName(companyName);
    e1.setDepartment(departmentName);
    e1.setNumTechnicians(5);


    cout << m1.getEmployeeName() << " (ID: " << m1.getEmployeeID() << ") works in " 
         << departmentName << " department of " << companyName 
         << " with an annual salary of $" << m1.getAnnualSalary() << endl;

    m1.calculateBonus();

    cout << endl;

    cout << e1.getEmployeeName() << " (ID: " << e1.getEmployeeID() << ") works in "
            << departmentName << " department of " << companyName 
            << " with an annual salary of $" << e1.getAnnualSalary() << endl;

    e1.calculateBonus();

    return 0;
}