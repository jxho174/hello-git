#include <iostream>
#include <fstream>
using namespace std;

class BinaryMemoryBlock
{
private:
    char *memory_block; // pointer to a block of memory
    int size;           // number of bytes

public:
    // Constructor
    BinaryMemoryBlock(int blockSize);

    // Member functions
    void setData();
    void writeToFile(string filename);
    void readFromFile(string filename);
    void displayData();

    // Destructor
    ~BinaryMemoryBlock();
};

// Constructor implementation
BinaryMemoryBlock::BinaryMemoryBlock(int blockSize)
{
    size = blockSize;
    memory_block = new char[size];

    cout << "Memory block created." << endl;
}

// Function implementation: put data into memory block
void BinaryMemoryBlock::setData()
{
    memory_block[0] = 10;
    memory_block[1] = 20;
    memory_block[2] = 30;
    memory_block[3] = 40;
}

// Function implementation: write memory block to binary file
void BinaryMemoryBlock::writeToFile(string filename)
{
    ofstream outFile(filename, ios::binary);

    if (!outFile)
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

    outFile.write(memory_block, size);

    outFile.close();

    cout << "Data written to binary file." << endl;
}

// Function implementation: read binary file into memory block
void BinaryMemoryBlock::readFromFile(string filename)
{
    ifstream inFile(filename, ios::binary);

    if (!inFile)
    {
        cout << "Error opening file for reading." << endl;
        return;
    }

    inFile.read(memory_block, size);

    inFile.close();

    cout << "Data read from binary file." << endl;
}

// Function implementation: display data inside memory block
void BinaryMemoryBlock::displayData()
{
    cout << "Data in memory block:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << (int)memory_block[i] << endl;
    }
}

// Destructor implementation
BinaryMemoryBlock::~BinaryMemoryBlock()
{
    delete[] memory_block;

    cout << "Memory block deleted." << endl;
}

int main()
{
    // Create object with 4 bytes of memory
    BinaryMemoryBlock block(4);

    // Put data into memory
    block.setData();

    // Write memory data into binary file
    block.writeToFile("data.bin");

    // Create another object for reading
    BinaryMemoryBlock readBlock(4);

    // Read data from binary file into memory
    readBlock.readFromFile("data.bin");

    // Display data read from file
    readBlock.displayData();

    return 0;
}