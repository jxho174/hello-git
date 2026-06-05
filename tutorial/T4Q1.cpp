#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Purchase {
    public:
        Purchase(string name = "", int quantity = 0, float p = 0.0);
        void set_data(string name, int quantity, float p);
        void calculate(void);
        void print(void);
        static void printtotal(const vector<Purchase>& purchase);

    private:
        int quantity;
        float price;
        string itemName;
        float total;
};

Purchase::Purchase(string name, int quantity, float p)
    : quantity(quantity), price(p), itemName(name){
        this->total = 0;
    }

void Purchase::set_data(string name, int quantity, float p)
{
    this->itemName = name;
    this->quantity = quantity;
    this->price = p;
}

void Purchase::calculate(void)
{
    this->total = this->price * this->quantity;
}

void Purchase::print(void)
{
    cout << "========================\n";
    cout << "Subtotal : RM " << this->total << endl;
    cout << "========================\n\n";
}

void Purchase::printtotal(const vector<Purchase>& purchase)
{
    int total_quantity = 0;
    float grand_total = 0.0;

    for (const Purchase& item : purchase) {
        total_quantity += item.quantity;
        grand_total += item.total;
    }

    cout << "========================\n";
    cout << "\tGRAND TOTAL\n";
    cout << "========================\n";
    cout << "Total number of items\t: " << total_quantity << endl;
    cout << "Total amount to be paid : RM" << grand_total << endl;
}

int integer_input(void)
{
    string prompt;
    getline(cin >> ws, prompt);
    try {
        return stoi(prompt);
    }
    catch (const invalid_argument& e) {
        cout << "Invalid input! Please enter a valid number: ";
        return integer_input();
    }
}

float float_input(void)
{
    string prompt;
    getline(cin >> ws, prompt);
    try {
        return stof(prompt);
    }
    catch (const invalid_argument& e) {
        cout << "Invalid input! Please enter a valid number: ";
        return float_input();
    }
}

int main()
{
    vector<Purchase> p1;
    Purchase item;
    string name;
    int quantity;
    float price;

    cout << "========================\n";
    cout << "\tWELCOME\n";
    cout << "========================\n";

    while(true)
    {
         cout << "Enter item ('Q' to quit) : ";
        getline(cin >> ws, name);

        if (name == "Q") {
            break;
        }

        cout << "Enter quantity  : ";
        quantity = integer_input();

        cout << "Enter price\t: RM ";
        price = float_input();

        item.set_data(name, quantity, price);
        item.calculate();
        item.print();
        p1.push_back(item);
    }

    Purchase::printtotal(p1);

    return 0;
}