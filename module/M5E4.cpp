#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line;
    ifstream file("example.txt");
    if (! file.is_open()) {
        return 1;
    }
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    
    return 0;
}