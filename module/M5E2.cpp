#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileStorage {
    ofstream myFile;
    string mfilename;

    public:
        FileStorage(string filename="") {
            // 1. RULE CHANGE: We must explicitly tell C++ to use binary mode!
            // (I also added ios::app so it doesn't delete your old saves)
            myFile.open(filename, ios::out | ios::app | ios::binary); 
            mfilename = filename;
        }

        // 2. THE ENCODER: Writing a string to binary
        void writeToBinary(const string& str) {
            
            // Step A: Calculate how long the string is
            size_t length = str.size();

            // Step B: Write the LENGTH to the file first
            // We pretend the 'length' variable is a character array, and dump its memory
            myFile.write((char*)&length, sizeof(length));

            // Step C: Write the actual CHARACTERS to the file
            // str.data() gets the raw characters. We write exactly 'length' amount of bytes.
            myFile.write(str.data(), length);
        }

        void closeFile() {
            myFile.close();
        }
};

int main()
{
    // Changed to .bin just to remind ourselves it isn't a text file anymore!
    FileStorage ff("example.bin"); 
    
    ff.writeToBinary("Damn Girl! You look bad. Cmon let me take you out somewhere\n");
    ff.writeToBinary("我爱冰淇凌\n");
    
    ff.closeFile();
    
    cout << "Data encoded and saved to binary successfully!" << endl;
    
    return 0;
}