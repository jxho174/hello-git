#include <iostream>
using namespace std;

int main()
{
    int choice, num1, num2;

    while(true) {
        cout << "Enter option: 1) + 2) - 3) * 4) / 5) mod(x1, x2) -1) exit: " << endl;
        cin >> choice;

        if (choice == -1) {
            cout << "Exiting..." << endl;
            break;
        }

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        switch(choice) {
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
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            case 5:
                if (num2 != 0) {
                    cout << num1 << " % " << num2 << " = " << num1 % num2 << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}