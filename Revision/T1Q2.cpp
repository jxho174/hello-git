#include <iostream>
using namespace std;

int main()
{
    float m, h;
    cout << "Get weight in kg: ";
    cin >> m;

    cout << "Get height in m: ";
    cin >> h;

    float bmi = m / (h * h);
    cout << "Your BMI is: " << bmi << endl;

    if (bmi < 18.5) {
        cout << "You are underweight." << endl;
    } else if (bmi >= 18.5 && bmi < 25) {
        cout << "You are normal weight." << endl;
    } else if (bmi >= 25 && bmi < 30) {
        cout << "You are overweight." << endl;
    } else {
        cout << "You are obese." << endl;
    }

    return 0;
}