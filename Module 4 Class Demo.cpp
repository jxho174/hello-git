#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    Student(string a_name) { name = a_name; }
    void changeAge(int a)
    {
        age = a;
    }
	
    string getName()
    {
        return name;
    }
	
    void setName(string a_name)
    {
        name = a_name;
    }
};

int main()
{

    Student s1(" John ");
    s1.changeAge(20); 
    cout << "\n Hello  " << s1.getName();

    return 1;
}
