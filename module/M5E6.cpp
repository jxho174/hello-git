#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

class BinaryMemoryBlock {
    private:
        string* memoryblock;
        int size;

    public:
        BinaryMemoryBlock(int s) {
            size = s;
            memoryblock = new string(size, '\0');
        }
        void setdata() {
            for (int i = 0; i < size; i++) {
                memoryblock[i] = "Data" + to_string(i); // Set some sample data in the memory block
            }
        }
        void writeToFile(string filename) {
            ofstream outFile(filename, ios::binary);
            if (outFile.is_open()) {
                for (int i = 0; i < size; i++) {
                    outFile.write(memoryblock[i].c_str(), memoryblock[i].size()); // Write each string to the file
                }
                outFile.close();
            } else {
                cerr << "Unable to open file for writing." << endl;
            }
        }
        void readFromFile(string filename) {
            ifstream inFile(filename, ios::binary);
            if (inFile.is_open()) {
                for (int i = 0; i < size; i++) {
                    char buffer[100]; // Buffer to hold the read string
                    inFile.read(buffer, sizeof(buffer)); // Read data into the buffer
                    memoryblock[i] = string(buffer); // Store the read string in the memory block
                }
                inFile.close();
            } else {
                cerr << "Unable to open file for reading." << endl;
            }
        }
        void displayData() {
            for (int i = 0; i < size; i++) {
                cout << memoryblock[i] << endl; // Display each string in the memory block
            }
        }

        ~BinaryMemoryBlock() {
            delete[] memoryblock;
        }
};

int main()
{
    BinaryMemoryBlock block(4); // Create a binary memory block of size 4
    block.setdata(); // Set data in the memory block
    block.writeToFile("data.bin"); // Write the data to a binary file named "data.bin"
    BinaryMemoryBlock readBlock(4); // Create another binary memory block to read the data
    readBlock.readFromFile("data.bin"); // Read the data from the binary file into the new memory block
    readBlock.displayData(); // Display the data read from the file to verify that it was read correctly

    return 0;
}