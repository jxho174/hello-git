#include <iostream>
using namespace std;

void square_generator(void) {
    string input;
    int value;
    while(true)
    {
        cout << "Enter the length of the side of the square between 1 to 20: ";
        getline(cin, input);
        try{
            value = stoi(input);
        }
        catch(const invalid_argument& e) {
            cout << "Ending program. Only integer values between 1 to 20 accepted";
            break;
        }

        if (value < 1 || value > 20) {
            cout << "Ending program. Only integer values between 1 to 20 accepted";
            break;
        }
        else {
            for (int i = 0; i < value; i++) {
                for (int j = 0; j < value; j++) {
                    cout << "* ";
                }
                cout << "\n";
            }
        }
        
    }
}

int main() {
    square_generator();
    return 0;
}