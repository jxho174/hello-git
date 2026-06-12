#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
        Student(string n, string id) {name=n; netID = id;}
        void print();

    protected:
        string name;
        int age;
        string netID;
};

class GradStudent : public Student {
    public:
        GradStudent(string n, string id, string prev);

        void print() {
            cout << endl << name << " " << netID << " " << prevDegree << endl;
        }

    protected:
        string prevDegree;
};

GradStudent::GradStudent(string n, string id, string prev) : Student(n, id) {
    prevDegree = prev; 
}


int main()
{
    GradStudent g("Ali", "123", "BEng EE");
    g.print();

    return 0;
}