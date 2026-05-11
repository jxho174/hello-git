#include <iostream>
using namespace std;

class Book{
    private:
        string title;
        float price;
        string currency;

    public:
        Book(string a_title, float a_price, string a_currency);
        float getPrice(); // return price inRM
        string getTitle(); // return title of book
        void showPriceTitle(); // display price in RM
};

Book::Book(string a_title, float a_price, string a_currency) {
    this->title = a_title;
    this->price = a_price;
    this->currency = a_currency;
};

float Book::getPrice(void) {
    return this->price;
}

string Book::getTitle(void) {
    return this->title;
}

void Book::showPriceTitle(void) {
    cout << "\nTitle of Book : " << Book::getTitle() << endl;
    cout << " Price in " << this->currency << " = " << Book::getPrice() << endl;
}

int main()
{
    Book b1("C++ is Fun", 50.0, "RM");
    cout <<"\n I just bought the book " << b1.getTitle();
    b1.showPriceTitle();
    cout <<endl ;

    Book b2("Snow White", 50.0, "USD");
    cout <<"\n I just bought the book " << b2.getTitle();
    b2.showPriceTitle();

    return 0;
}