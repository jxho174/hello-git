#include <iostream>
using namespace std;

class Book {
    private:
        string title;
        int pages;
    public:
        Book() { title="None"; pages=0; }
        Book(string t, int p) : title(t), pages(p) {}

        void print(int id) const {
            cout << id << " Title: " << title << ", Pages: " << pages << endl;
        }
        string getBookTitle() const { return title; }
};

class Library {
    private:
        Book* pbooks; // Library has many books
        int numBook;
    public:
        //Library() : books{Book("Book 1", 100), Book("Book 2", 200), Book("Book 3",
        //300)} {}
        Library(int n) : numBook(n)
        {
            pbooks = new Book[ numBook ] ;
        }
        ~Library() { delete[] pbooks; }
        void printBooks() const {
            for (int i = 0; i < numBook; ++i) {
                pbooks[i].print(i);
            }
        }
        void addBook( Book bb, int i)
        {
            if (i < 0 || i >= numBook) {
                cout << "Error: index " << i << " is out of bounds" << endl;
                return;
            }
            pbooks[i] = bb;
        }
};

int main() {
    Library library(3);
    library.printBooks();

    Book bb[3];
    bb[0] = Book("Hello Guys", 200) ;
    bb[1] = Book("Bye Bye", 300) ;
    bb[2] = Book("The book", 350) ;

    // Alternative is Book bb[3] = { Book("Hello Guys", 200) ,Book("Bye Bye", 300) ,Book("The book", 350) } ;
    for (int i=0; i<3 ; i++)
    { library.addBook( bb[i], i) ; }
    cout <<endl;
    library.printBooks();

    // Error added below, fix it
    library.addBook( Book("C++ Is Fun", 800), 4 ) ;
    library.printBooks();
    Book b1("My book is good", 0);
    Book *b2 = new Book() ;
    b2->print(2);
    cout << b1.getBookTitle() << endl;
    delete b2;
    return 0;
}