#include <iostream>
using namespace std;

class Student{
    private:
        string name;
        int age;
        double cgpa;
    public:
        Student(string a_name = "", int a_age = 18, double a_cgpa = 3.00) {
            this->name = a_name;
            this->age = a_age;
            this->cgpa = a_cgpa;
        }
        void print_info() {
            cout << "Student Name: " << this->name << endl;
            cout << "Student Age: " << this->age << endl;
            cout << "Student CGPA: " << this->cgpa << endl;
        }
};


int main() {
    Student s1;
    s1.print_info();

    return 0;
}