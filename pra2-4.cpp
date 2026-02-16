#include <iostream>
using namespace std;

class Item {
private:
    int itemID;
    string name;
    double price;
    int quantity;

public:
    Item();
    Item(int, string, double, int);

    void input();
    void addStock(int);
    void sellItem(int);
    void display();
};


Item::Item() {
    itemID = 0;
    name = "";
    price = 0;
    quantity = 0;
}


Item::Item(int id, string n, double p, int q) {
    itemID = id;
    name = n;
    price = p;
    quantity = q;
}


void Item::input() {
    cout << "Enter Item ID: ";
    cin >> itemID;

    cout << "Enter Item Name: ";
    cin >> name;

    cout << "Enter Price: ";
    cin >> price;

    cout << "Enter Quantity: ";
    cin >> quantity;

}


void Item::addStock(int amount) {
    quantity += amount;
}


void Item::sellItem(int amount) {
    if (amount <= quantity) {
        quantity -= amount;
        cout << "Sale successful.\n";
    } else {
        cout << "Not enough stock available.\n";
    }
}


void Item::display() {
    cout << "ID: " << itemID
         << " | Name: " << name
         << " | Price: " << price
         << " | Quantity: " << quantity << endl;
}

int main() {

    Item store[10];

    cout << "Enter details for 10 items:\n";

    for (int i = 0; i < 10; i++) {
        cout << "\nItem " << i + 1 << endl;
        store[i].input();
    }

    cout << "\nInventory Details:\n";
    for (int i = 0; i < 10; i++) {
        store[i].display();
    }

    int choice, itemNo, qty;

    cout << "\n1. Add Stock\n2. Sell Item\nEnter choice: ";
    cin >> choice;

    cout << "Enter item number (1-10): ";
    cin >> itemNo;

    cout << "Enter quantity: ";
    cin >> qty;

    if (choice == 1)
        store[itemNo - 1].addStock(qty);
    else if (choice == 2)
        store[itemNo - 1].sellItem(qty);

    cout << "\nUpdated Inventory:\n";
    for (int i = 0; i < 10; i++) {
        store[i].display();
    }

    return 0;
}
