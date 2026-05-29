#include <string>
#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;

public:
    void speak() { cout << "\n ???"; }
};

class Cat : public Animal
{
public:
    void speak() { cout << "\n Meow"; }
};

int main()
{
    Cat c1;
    c1.speak(); // Meow

    Animal *pAnimal;
    pAnimal = &c1;
    pAnimal->speak(); // ???
    return 1;
}