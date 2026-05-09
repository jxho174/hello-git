#include <iostream>
using namespace std;

double double_input(void) {
    string x;
    getline(cin, x);
    try {
        return stod(x);
    } catch (const invalid_argument& e) {
        cout << "Invalid input! Please enter a valid number: ";
        return double_input(); // Recursively call until valid input is received
    }
    
}

int main()
{
    double width, height, area;
    cout << "Enter the width of the triangle: ";
    width = double_input();

    cout << "Enter the height of the triangle: ";
    height = double_input();

    area = 1.0 / 2.0 * width * height;
    cout << "The area of the triangle is: " << area << "cm^2\n";

    return 0;
}