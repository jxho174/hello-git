#include <iostream>
#include <memory>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    unique_ptr<int[]> array = make_unique<int[]>(size);

    for (int i = 0; i < size; i++) {
        cout << "Enter " << i << " number: ";
        cin >> array[i];
    }

    cout << "\nYou entered: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}