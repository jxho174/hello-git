#include <iostream>
#include <cmath> // Required for sqrt() and pow()
using namespace std;

// 1. Point MUST be defined first!
class Point {
    public:
        Point(int a_x = 0, int a_y = 0) : x(a_x), y(a_y) {}
        
        void setPoint(int a_x, int a_y) {
            x = a_x;
            y = a_y;
        }

        // Getters so the Line class can read the coordinates to do math
        int getX() const { return x; }
        int getY() const { return y; }

    private:
        int x, y;
};

// 2. Line is defined second, using the Point class
class Line {
    public:
        // Constructor takes a pointer to an OUTSIDE array (This is True Aggregation)
        Line(Point* points) : pArray(points) {}

        double getLength() const {
            double totalLength = 0;
            
            // Loop through the segments: Point 0 to 1, then Point 1 to 2
            for (int i = 0; i < 2; i++) {
                // Get the differences in X and Y
                double dx = pArray[i+1].getX() - pArray[i].getX();
                double dy = pArray[i+1].getY() - pArray[i].getY();
                
                // Calculate Euclidean distance and add it to the total
                totalLength += sqrt(pow(dx, 2) + pow(dy, 2));
            }
            
            return totalLength;
        }

    private:
        Point* pArray; // Pointer to the aggregated array
};

int main()
{
    // 1. Create the points independently in main()
    Point myPoints[3];
    myPoints[0].setPoint(1, 2);
    myPoints[1].setPoint(3, 4);
    myPoints[2].setPoint(1, 9);

    // 2. Pass the array into the Line (Aggregation)
    // Arrays automatically act as pointers when passed like this!
    Line myLine(myPoints);

    // 3. Calculate and output
    cout << "Total Euclidean Length: " << myLine.getLength() << endl;

    return 0;
}