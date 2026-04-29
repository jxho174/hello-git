#include <iostream>
using namespace std;

void displayVector(float *a_array, int numElem);
void getInputIntoVector(float *a_array, int numElem);

int main()
{
    int numElem;

    cout << "Enter how many numbers to enter >> ";
    cin >> numElem;

    float *a_arry = new float[numElem];
    getInputIntoVector(a_arry, numElem);

    displayVector(a_arry, numElem);
    delete[] a_arry;

    return 1;
}

void displayVector(float *a_array, int numElem) {
    cout << "\nNumber of elements in array = " << numElem << endl;

    cout << "\nDisplay data in array\n";
    for (int i = 0; i < numElem; i++) {
        cout << a_array[i] << " ";
    }
    cout << endl;
}

void getInputIntoVector(float *a_array, int numElem) {
    for (int i = 0; i < numElem; i++) {
        cout << "\nEnter element A[" << i << "] = ";
        cin >> a_array[i];
    }
}