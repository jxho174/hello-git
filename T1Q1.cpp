#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int integer_input(void);

int main()
{
    string input;
    int symbol = 0, num1 = 0, num2 = 0;

    cout << "Simple calculator" << endl;
    while(true) {
        cout << "Enter option: 1)+ 2)- 3)* 4)/ 5) mod(x1, x2) -1) Exit  Your selection -> ";
        symbol = integer_input();
        if (symbol == -1) {
            break;
        }
        else if (symbol < 1 || symbol > 5) {
            cout << "Invalid option! Please try again." << endl;
            continue;
        }

        cout << "Enter first number: ";
        num1 = integer_input();
        cout << "Enter second number: ";
        num2 = integer_input();

        cout << endl;

        switch(symbol) {
            case 1:
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;
            case 2:
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;
            case 3:
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;
            case 4:
                if (num2 != 0) {
                    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                }
                else {
                    cout << "Cannot divide by zero!" << endl;
                }
                break;
            case 5:
                if (num2 != 0) {
                    cout << "mod(" << num1 << ", " << num2 << ") = " << num1 % num2 << endl;
                }
                else {
                    cout << "Cannot divide by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
                break;
        }
    }

    return 0;
}

// try and catch for invalid input and out of range input
int integer_input(void) {
    string input;
    int integer;
    while(true) {
        getline(cin, input);
        try {
            integer = stoi(input);
            return integer; // Moved this inside the try block so it only returns if stoi succeeds
        }
        catch(const invalid_argument& e) {
            cout << "Invalid input! Please enter an integer: ";
            continue;
        }
        catch(const out_of_range& e) {
            cout << "Number is too large! Please enter a smaller integer: ";
            continue;
        }
    }
}