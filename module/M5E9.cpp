#include <iostream>
#include <exception>
#include <new>
using namespace std;

int main()
{
    try {
        int *array = new int[1000000000000]; // Attempt to allocate a very large array
    }
    catch (const bad_alloc& e) {
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}