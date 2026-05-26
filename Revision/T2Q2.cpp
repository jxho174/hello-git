#include <iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter the length of the side of the square between 1 and 20: ";
    cin >> str;

    int side = stoi(str);
    if (side < 1 || side > 20) {
        cout << "Invalid input. Please enter a number between 1 and 20." << endl;
        return 1;
    }
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}