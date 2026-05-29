#include <iostream>
using namespace std;

class Shape {
    public:
        virtual void Draw()
        {
            cout << "Drawing Shape" << endl;
        }
};

class Circle : public Shape {
    public:
        void Draw()
        {
            cout << "Drawing Circle" << endl;
        }
};

class Triangle : public Shape {
    public:
        void Draw()
        {
            cout << "Drawing Triangle" << endl;
        }
};

int main()
{
    Shape *s;
    Circle c;
    Triangle t;

    s = &c;
    s->Draw();
    s = &t;
    s->Draw();

    return 0;
}