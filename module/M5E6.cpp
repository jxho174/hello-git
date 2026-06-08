#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

class BinaryMemoryBlock {
    private:
        unique_ptr<string> memoryblock;
        int size;

    public:
        BinaryMemoryBlock(int s) {
            size = s;
            memoryblock = make_unique<string>(size, '\0');
        }
        void setdata() {

        }
        void writeToFile() {

        }
        void readFromFile() {

        }
        void displayData() {

        }
};

int main()
{

    return 0;
}