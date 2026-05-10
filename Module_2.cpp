#include <iostream>
#include <string>
#include <limits>
#include <numeric>
using namespace std;

int main()
{
    // string message("Hello");
    // cout << message << endl;

    // cout << "Enter a new message without space: ";
    // cin >> message;
    // cout << message << endl;

    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // [NEW] Clear the input buffer before using getline
    // cout << "Enter a new message with space: ";
    // getline(cin >> ws, message);
    // cout << message << endl;

    int marks[] = {74, 43, 58, 60, 90, 64, 70};
    int total = accumulate(begin(marks), end(marks), 0); // [NEW] Using std::accumulate to sum the array
    cout << "Total marks: " << total << endl;

    return 0;
}