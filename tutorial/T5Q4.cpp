#include <iostream>
using namespace std;

class Book {
    friend class Author;
    public:
        Book(string t = "None", int p = 0) : title(t), pages(p) {}

        void print(int id) const {
            cout << id << " Title: " << title << ", Pages: " << pages << endl;
        }

    private:
        string title;
        int pages;
};

class Library {
    public:
        Library(int numBook)
        {
            pbooks = new Book[ numBook ] ;
        }
        void printBooks() const {
            for (int i = 0; i < 3; ++i) {
                pbooks[i].print(i);
            }
        }
        void addBook( Book bb, int i)
        {
            pbooks[i] = bb;
        }
    private:
        Book* pbooks;
};

class Author {
    private: 
        string name;
    public:
        Author(string n = "Unknown") : name(n) {}
        void printBooks(const Library& lib) const {
            cout << "Books by " << name << ":" << endl;
            lib.printBooks();
        }
};


int main()
{
    Library library(4);
    library.printBooks();
    Book bb[4];
    bb[0] = Book("Hello Guys", 200);
    bb[1] = Book("Bye Bye", 300);
    bb[2] = Book("The book", 350);
    bb[3] = Book("C++ Is Fun", 800);

    for (int i=0; i<4 ; i++)
    { library.addBook( bb[i], i) ; }

    cout <<endl;
    library.printBooks();

    return 0;
}