#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string customerName;
    int accountID;
    double balance;

public:

    void createAccount() {
        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, customerName);

        cout << "Enter account ID: ";
        cin >> accountID;

        cout << "Enter initial balance: ";
        cin >> balance;

        if (balance < 0) {
            cout << "Initial balance cannot be negative. Setting balance to 0.\n";
            balance = 0;
        }
    }

    void deposit() {
        double amount;
        cout << "Enter deposit amount: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter withdrawal amount: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid withdrawal amount!\n";
        }
        else if (amount > balance) {
            cout << "Insufficient balance! Withdrawal denied.\n";
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        }
    }

    void displaySummary() {
        cout << "\n--- Account Summary ---\n";
        cout << "Customer Name: " << customerName << endl;
        cout << "Account ID   : " << accountID << endl;
        cout << "Balance      : " << balance << endl;
    }
};

int main() {
    Account account;
    int choice;

    account.createAccount();

    do {
        cout << "\n1. Deposit Money";
        cout << "\n2. Withdraw Money";
        cout << "\n3. Display Account Summary";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            account.deposit();
            break;
        case 2:
            account.withdraw();
            break;
        case 3:
            account.displaySummary();
            break;
        case 4:
            cout << "Thank you for using the Digital Savings Account System.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
