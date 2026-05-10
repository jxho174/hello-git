#include <iostream>
#include <memory>
using namespace std;

void swap(int* num1, int* num2);
void sumAverage(const float *pArray, int size, float& a_sum, float& a_average);

int main()
{
    // int num1 = 2;
    // int num2 = 3;

    // cout << num1 << endl;
    // cout << num2 << endl;

    // swap(&num1, &num2);
    // cout << num1 << endl;
    // cout << num2 << endl;

    float sum = 0, average = 0;
    float array[4] = {1.0, 2.0, 3.0, 4.0};
    int numElem = sizeof(array) / sizeof(array[0]);

    sumAverage(array, numElem, sum, average);
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    return 0;
}

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void sumAverage(const float *pArray, int size, float& a_sum, float& a_average)
{
    for (int i = 0; i < size; i++) {
        a_sum += pArray[i];
    }
    a_average = a_sum / size;
}