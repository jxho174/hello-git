#include <iostream>
#include <cmath>
using namespace std;

class Point {
    friend class Line; // Declare Line as a friend class to access private members of Point
    public:
        Point(int a_x = 0, int a_y = 0) : x(a_x), y(a_y) {}
    private:
        int x;
        int y;
};

class Line {
    private:
        Point point1;
        Point point2;
    public:
        Line(Point p1, Point p2) : point1(p1), point2(p2) {}
        int length(void) {
            int dx = pow(point2.x - point1.x, 2);
            int dy = pow(point2.y - point1.y, 2);
            return sqrt(dx + dy);
        }
};

int main()
{
    Point p1(0, 0);
    Point p2(3, 4);
    Line line1(p1, p2);

    cout << "Length of line: " << line1.length() << endl;

    return 0;
}