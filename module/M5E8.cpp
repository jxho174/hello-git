#include <iostream>
#include <limits>
using namespace std;

double division(int a, int b) {
    if( b == 0 ) {
        throw "Division by zero condition!";
    }
    return (a/b);
}

int main() 
{
    int x = 50, y = 0; 
    double z = 0;

    try {
        z = division(x, y);
        cout << "Result: " << z << endl;
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    return 0;
}