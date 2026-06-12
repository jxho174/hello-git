#include <iostream>
using namespace std;

class Shape {
    public:
        virtual void draw() {
            cout << "Drawing a shape" << endl;
        }
};

class Circle : public Shape {
    public:
        void draw() {
            cout << "Drawing a circle" << endl;
        }
};

class Rectangle : public Shape {
    public:
        void draw() {
            cout << "Drawing a rectangle" << endl;
        }
};

int main(){

    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw(); // Output: Drawing a circle
    shape2->draw(); // Output: Drawing a rectangle

    return 0;
}