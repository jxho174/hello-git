#include <iostream>
using namespace std;

void swap(int &a, int &b);

int main() {
    int x = 2, y = 4;
    cout << "\nx = " << x;
    cout << "\ny = " << y;
    swap(x, y);
    cout << "\nAfter swapping\n";
    cout << "\nx = " << x;
    cout << "\ny = " << y;
    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}