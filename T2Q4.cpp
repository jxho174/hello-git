#include <iostream>
using namespace std;
void getMinMax(int* p_array, int size, int &a_min, int &a_max);
void showArray(int* p_array, int size);
int main()
{
int myArray[] = {3, 8, 11, 2};
int min = 10000, max = 0;
int numItem = sizeof(myArray)/sizeof(int) ;
showArray(myArray, numItem);
getMinMax(myArray, numItem, min, max);
cout << "\n The maximum = " << max;
cout << "\n The minimum = " << min;
return 1;
}