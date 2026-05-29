#include <iostream>
#include <memory>
using namespace std;

class TradesPerson { // base class
    public:
        virtual ~TradesPerson() = default;

        virtual void sayHi( ) { 
            cout << "Just hi." << endl;
        }
};

class Tinker : public TradesPerson { // derived class 1
    public:
        virtual void sayHi( ) { 
            cout << "Hi, I'm a tinker." << endl;
        }
};

class Tailor : public TradesPerson { // derived class 2
    public:
        virtual void sayHi( ) { 
            cout << "Hi. I'm a tailor." << endl;
        }
};

int main()
{
    unique_ptr<TradesPerson> p; // pointer to base class object
    int selection;
    cout << "1 == TradesPerson, 2 == Tinker, 3 == Tailor : ";
    cin >> selection;
    switch(selection ) {
        case 1: p = unique_ptr<TradesPerson>(new TradesPerson()); break;
        case 2: p = unique_ptr<TradesPerson>(new Tinker()); break;
        case 3: p = unique_ptr<TradesPerson>(new Tailor()); break;
        default: cout << "Invalid selection." << endl; return 1;
    }
    p->sayHi(); // call the method

    return 0;
}