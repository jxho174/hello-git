#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    double weight = 0, height = 0, bmi = 0;
    string category;
    cout << "Get weight in kg: ";
    weight = double_input();

    cout << "Get height in meter: ";
    height = double_input();

    bmi = weight / pow(height, 2);
    cout << "Your bmi = " << bmi << endl;

    // Categorize the BMI value
    if (bmi < 18.5) {
        category = "Underweight";
    }
    else if (bmi >= 18.5 && bmi <= 24.9) {
        category = "Healthy";
    }
    else if (bmi >= 25 && bmi <= 29.9) {
        category = "Overweight";
    }
    else if (bmi >= 30) {
        category = "Obesity";
    }

    cout << "Your weight category is : " << category << endl;
    return 0;
}

// try and catch for invalid input and out of range input
double double_input(void) {
    string input;
    double value;
    while (true) {
        getline(cin, input);
        try {
            value = stod(input);
            return value; // Moved this inside the try block so it only returns if stod succeeds
        }
        catch(const invalid_argument& e) {
            cout << "Invalid input! Please enter a number: ";
            continue;
        }
        catch(const out_of_range& e) {
            cout << "Number is too large! Please enter a smaller number: ";
            continue;
        }
    }
}