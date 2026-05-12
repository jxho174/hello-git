#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Item {
    public:
        Item(string a_name = "", int a_value = 0) : name(a_name), value(a_value) {}
        void setName(string a_name) {
            name = a_name;
        }
        void setValue(int a_value) {
            value = a_value;
        }
        void display() const {
            cout << name << "(" << value << "g)" << endl;
        }

    private:
        string name;
        int value;
};

class Inventory {
    public:
        Inventory() : backpack() {}
        void addItem(unique_ptr<Item> newItem) { backpack.push_back(std::move(newItem)); }
        void displayInventory() const {
            for (const auto& item : backpack) {
                item->display();
            }
        }
    private:
        vector<unique_ptr<Item>> backpack;
};

int main() {
    Inventory myBackpack;

    // 1. Create items on the Heap using 'new'
    auto sword = make_unique<Item>("Iron Sword", 150);
    auto potion = make_unique<Item>("Health Potion", 50);

    // 2. Add them to the inventory
    myBackpack.addItem(std::move(sword));
    myBackpack.addItem(std::move(potion));

    // 3. Show what we have
    cout << "--- My Inventory ---" << endl;
    myBackpack.displayInventory();

    return 0;
}