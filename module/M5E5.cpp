#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    ifstream myfile("example.txt");

    if (! myfile.is_open()) {
        return 1;
    }

    while (! myfile.eof()) { // This display word by word
        myfile >> line;
        cout << line << endl;
    }

    myfile.close();

    return 0;
}