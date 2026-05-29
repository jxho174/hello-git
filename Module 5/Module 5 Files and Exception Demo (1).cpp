#include <iostream>
#include <fstream>
using namespace std;
class FileStorage
{
	ofstream mfile; // obj to store text in file
	string mfilename;

public:
	FileStorage(string filename)
	{
		mfile.open(filename);
		mfilename = filename;
	}

	void writeToFile(string str) { mfile << str; }
};

int main()
{
	FileStorage ff("example.txt");
	ff.writeToFile("Writing this to a file.\n");
}
