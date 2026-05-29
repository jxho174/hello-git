
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // =========================
    // PART 1: WRITE BINARY FILE
    // =========================

    char *memory_block = new char[4];

    memory_block[0] = 10;
    memory_block[1] = 20;
    memory_block[2] = 30;
    memory_block[3] = 40;

    ofstream outFile("data.bin", ios::binary);

    outFile.write(memory_block, 4);

    outFile.close();

    delete[] memory_block;

    cout << "Data written to file." << endl;

    // ========================
    // PART 2: READ BINARY FILE
    // ========================

    char *read_block = new char[4];

    ifstream inFile("data.bin", ios::binary);

    inFile.read(read_block, 4);

    inFile.close();

    cout << "Data read from file:" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << (int)read_block[i] << endl;
    }

    delete[] read_block;

    return 0;
}