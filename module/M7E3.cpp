#include <iostream>
using namespace std;

class Animal { // ABC
    protected:
        string name;

    public:
        virtual void makeSound() = 0; // Pure virtual function

};

class Dog : public Animal {
    public:
        Dog(string n) {
            name = n;
        }

        void makeSound() {
            cout << name << " says: Woof!" << endl;
        }
};

class Cat : public Animal {
    public:
        Cat(string n) {
            name = n;
        }

        void makeSound() {
            cout << name << " says: Meow!" << endl;
        }
};

int main() {

    Dog dog("Buddy");
    Cat cat("Whiskers");

    dog.makeSound(); // Output: Buddy says: Woof!
    cat.makeSound(); // Output: Whiskers says: Meow!

    return 0;
}