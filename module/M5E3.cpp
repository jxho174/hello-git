#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myFile("example.txt");
    if (! myFile.is_open()) {
        cout << "Unable to open file\n";
        return 1;
    }
    
    myFile << "This is a line.\n";
    myFile << "This is another line.\n";
    myFile.close();

    return 0;
}