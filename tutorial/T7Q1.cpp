#include <iostream>
using namespace std;

class Shape {
    protected:
        string nameOfShape;
        double width, height;

    public:
        string getName(void) {return nameOfShape;}
};

class Rectangle : public Shape {
    public:
        Rectangle(string name, double width, double height);
        double getArea();
};

class Triangle : public Shape {
    public:
        Triangle(string name, double width, double height);
        double getArea();
};

Rectangle::Rectangle(string name, double a_width, double a_height) {
    nameOfShape = name;
    width = a_width;
    height = a_height;
}

double Rectangle::getArea() {
    return width * height;
}

Triangle::Triangle(string name, double a_width, double a_height) {
    nameOfShape = name;
    width = a_width;
    height = a_height;
}

double Triangle::getArea() {
    return 0.5 * width * height;
}

int main()
{
    Rectangle r1("My rectangle", 2.0, 4.0);
    Triangle t1("My triangle", 2.0, 4.0);

    cout << r1.getName() << " area = " << r1.getArea() ;
    cout << endl;
    cout << t1.getName() << " area = " << t1.getArea() ;
    cout << endl;

    return 1;
}