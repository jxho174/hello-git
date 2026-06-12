#include <iostream>
using namespace std;

class TradePerson {
    public:
        virtual void sayHi() {
            cout << "Just hi" << endl;
        }
};

class Tinker : public TradePerson {
    public:
        void sayHi() {
            cout << "Hi, I'm a tinker" << endl;
        }
};

class BlackSmith : public TradePerson {
    public:
        void sayHi() {
            cout << "Hi, I'm a blacksmith" << endl;
        }
};

int main()
{
    TradePerson* p;
    cout << "Enter 1. TradePerson, 2. Tinker, 3. BlackSmith: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            p = new TradePerson();
            break;
        case 2:
            p = new Tinker();
            break;
        case 3:
            p = new BlackSmith();
            break;
        default:
            cout << "Invalid choice" << endl;
            return 1;
    }
    p->sayHi();

    return 0;
}