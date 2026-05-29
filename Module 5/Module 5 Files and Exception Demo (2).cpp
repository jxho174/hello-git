

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Step 1: Create a memory block of 4 bytes
    char *memory_block = new char[4];

    // Step 2: Open file in binary mode
    ifstream file("data.bin", ios::binary);

    // Step 3: Read 4 bytes from file into memory_block
    file.read(memory_block, 4);

    // Step 4: Close file
    file.close();

    // Step 5: Display data
    cout << "Data read from file:" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << (int)memory_block[i] << endl;
    }

    // Step 6: Free memory
    delete[] memory_block;

    return 0;
}