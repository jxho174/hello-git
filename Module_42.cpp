#include <iostream>
#include <string>
using namespace std;

class Teacher {
    public:
        Teacher(string a_subject = "") : subject(a_subject) {}
        void setSubject(string a_subject) {
            subject = a_subject;
        }
        string getSubject(void) {
            return subject;
        };
    private: 
        string subject;
};

class Department {
    public:
        // Constructor takes a pointer to a Teacher
        Department(Teacher* teacher = nullptr) : teacherPtr(teacher) {}

        void display() const {
            // It's always safe to check if the pointer is null before using it!
            if (teacherPtr != nullptr) {
                // We use -> instead of . because teacherPtr is a pointer
                cout << "Subject taught: " << teacherPtr->getSubject() << endl;
            } else {
                cout << "No teacher assigned!" << endl;
            }
        }
        
    private:
        // REQUIREMENT MET: Teacher object as member, represented by pointer
        Teacher* teacherPtr; 
};

int main()
{
    // 1. Create a normal Teacher object
    Teacher t1("Mathematics");

    // 2. Create a Department and pass the ADDRESS (&) of the teacher to fulfill the pointer requirement
    Department d1(&t1);

    // 3. Test it out
    d1.display();

    return 0;
}