#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main()
{
    int x = 4;
    cout << "Factorial of " << x << " is: " << factorial(x) << endl;
    return 0;
}