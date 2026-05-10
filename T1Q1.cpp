#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

void print_menu(void);
int int_input(void);
void operation(int option, int num1, int num2); // Changed to void since it handles its own printing

int main()
{
    while(true) 
    {
        print_menu();
        int option = int_input(); 
        
        // Proper C++ control flow for your loop
        if (option == -1) {
            cout << "Exiting calculator. Goodbye!\n";
            break; 
        }
        if (option < 1 || option > 5) {
            cout << "Invalid option! Please try again.\n\n";
            continue;
        }

        cout << "Enter first number: ";
        int num1 = int_input();

        cout << "Enter second number: ";
        int num2 = int_input();

        // Call the function to do the math and print the result
        operation(option, num1, num2);
        cout << endl; // Extra space for readability
    }
    return 0;
}

void print_menu(void) {
    cout << "--- Simple Calculator ---\n";
    cout << "Enter option: \n";
    cout << "1. +\n";
    cout << "2. -\n";
    cout << "3. *\n";
    cout << "4. /\n";
    cout << "5. mod(x1, x2)\n";
    cout << "-1. Exit\n";
    cout << "Your selection -> ";
}

int int_input(void)
{
    string prompt;
    // An infinite loop here is safer than having the function call itself over and over!
    while (true) {
        getline(cin >> ws, prompt);

        try {
            return stoi(prompt);
        } catch (const invalid_argument& e) {
            cout << "Invalid argument! Please enter a valid integer: ";
        } catch (const out_of_range& e) {
            cout << "Number is too large! Please enter a smaller integer: ";
        }
    }
}

void operation(int option, int num1, int num2)
{
    switch(option) {
        case 1:
            cout << num1  << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case 2:
            cout << num1  << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case 3:
            cout << num1  << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case 4:
            if (num2 != 0) {
                // If you want accurate division (like 5 / 2 = 2.5), you should cast to double!
                cout << num1  << " / " << num2 << " = " << (double)num1 / num2 << endl;
            }
            else {
                cout << "Error: Cannot divide by 0\n";
            }
            break;
        case 5:
            if (num2 != 0) {
                cout << "mod(" << num1 << ", " << num2 << ") = " << num1 % num2 << endl;
            }
            else {
                cout << "Error: Cannot modulo by 0\n";
            }
            break;
    }
}