#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;

// 1. Prototype added so main() knows this exists!
double double_input(void); 

int main()
{
    double weight = 0, height = 0, bmi = 0;
    string category;
    
    cout << "Get weight in kg: ";
    weight = double_input();

    while(true) {
        cout << "Get height in meter: ";
        height = double_input();

        if (height > 3) {
            cout << "Please enter your height in meter.\n";
            cout << "Aint no way someone " << height << "m this talls!\n\n";
        }
        else {
            break; // Valid height, escape the loop!
        }
        // 2. Removed the redundant 'continue' that was here
    }

    bmi = weight / pow(height, 2);
    cout << "Your bmi = " << bmi << endl;

    // 3. Fixed the continuous number boundaries
    if (bmi < 18.5) {
        category = "Underweight";
    }
    else if (bmi < 25.0) { 
        category = "Healthy";
    }
    else if (bmi < 30.0) {
        category = "Overweight";
    }
    else { // Catches 30.0 and anything higher
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