#include <iostream>
#include <vector>
#include <string>
#include <limits> // [NEW] Needed for the robust cin.ignore

using namespace std;

class Purchase{
    private:
        string itemName;
        int quantity;
        float price;
        float total;
    public:
        Purchase();
        Purchase(string itemName, int quantity, float price);
        void set_data(string itemName, int quantity, float price);
        void calculate();
        void print();
        float getTotal(); // [NEW] We need a public getter to read the private 'total'
};

Purchase::Purchase() {
    itemName = "";
    quantity = 0;
    price = 0.0;
    total = 0.0;
}

Purchase::Purchase(string itemName, int quantity, float price) {
    this->itemName = itemName;
    this->quantity = quantity;
    this->price = price;
    this->total = 0.0; 
}

void Purchase::set_data(string itemName, int quantity, float price) {
    this->itemName = itemName;
    this->quantity = quantity;
    this->price = price;
}

void Purchase::calculate() {
    total = quantity * price;
}

void Purchase::print() {
    cout << "================================\n";
    cout << "Subtotal\t: RM " << total << endl;
    cout << "================================\n";
}

// [NEW] Implementation of the getter
float Purchase::getTotal() {
    return total;
}

// [NEW] We must pass the vector into this function so it can see it!
void getSubtotal(vector<Purchase> all_purchases) {
    float subtotal = 0.0; // [NEW] Initialize our subtotal variable
    
    // [NEW] Correct C++ syntax for looping through a vector
    for (Purchase p : all_purchases) {
        subtotal += p.getTotal(); // Ask the class for the private total safely
    }
    
    cout << "\n================================\n";
    cout << "GRAND SUBTOTAL: RM " << subtotal << endl;
    cout << "================================\n";
}

int main()
{
    cout << "================================\n";
    cout << "\tWELCOME\n";
    cout << "================================\n";

    vector <Purchase> purchases;
    Purchase p;
    
    string itemName;
    int quantity;
    float price;

    while(true)
    {
        cout << "\nEnter item ('Q' to quit): ";
        getline(cin, itemName);

        // [NEW] Proper C++ string comparison
        if (itemName == "Q" || itemName == "q") {
            break; 
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        cout << "Enter price: RM ";
        cin >> price;

        // [NEW] CRITICAL FIX: Flush the Enter key out of the pipeline!
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        p.set_data(itemName, quantity, price);
        p.calculate();
        p.print();

        purchases.push_back(p);
    }

    // [NEW] Pass the vector into our function
    getSubtotal(purchases);

    return 0;
}