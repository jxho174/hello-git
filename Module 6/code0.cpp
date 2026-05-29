#include <string>
#include <iostream>
using namespace std;

class Student
{
protected:
    int id;
};

class GradStudent : public Student
{
    string prevDegree;

public:
    GradStudent()
    {
        id = 99;
        prevDegree = " EE";
    }
    void showInfo()
    {
        cout << "\n StudentInfo : \n"
             << id << endl
             << prevDegree;
    }
};

int main()
{
    GradStudent gs;
    gs.showInfo();
}