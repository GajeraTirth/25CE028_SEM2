#include<iostream>
using namespace std;

class Account {
private:
int accountNumber;
string holderName;
double balance;

public:

static int totalAccounts;

    Account() {}

    Account(int accNo, string name, double bal) {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
        totalAccounts++;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void setHolderName(string name) {
        holderName = name;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << holderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "-------------------------" << endl;
    }
};
    int Account::totalAccounts = 0;


int findAccount(Account *accounts, int size, int accNo) {
    for (int i = 0; i < size; i++) {
        if (accounts[i].getAccountNumber() == accNo)
            return i;
    }
    return -1;
}
void transferMoney(Account *accounts, int size, int fromAcc, int toAcc, double amount) {
    int fromIndex = findAccount(accounts, size, fromAcc);
    int toIndex = findAccount(accounts, size, toAcc);

    if (fromIndex == -1 || toIndex == -1) {
        cout << "Invalid account number.\n";
        return;
    }

    if (accounts[fromIndex].withdraw(amount)) {
        accounts[toIndex].deposit(amount);
        cout << "Transfer successful.\n";
    } else {
        cout << "Insufficient balance.\n";
    }
}

int main()
{
    int maxAccount=100;
    Account *accounts = new Account[maxAccount];
    int count = 0;
    int choice;
    do{
        cout << "----community Bank"<< endl;
        cout << "1. Add Account\n"<<endl;
        cout << "2. Update Holder Name\n"<<endl;
        cout << "3. Transfer Money\n"<<endl;
        cout << "4. Display Accounts\n"<<endl;
        cout << "5. Show Total Accounts\n"<<endl;
        cout << "0. Exit\n"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;

    if (choice == 1) {
            int accNo;
            string name;
            double balance;

            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Holder Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> balance;

            accounts[count] = Account(accNo, name, balance);
            count++;

            cout << "Account created successfully.\n";
        }

        else if (choice == 2) {
            int accNo;
            string newName;

            cout << "Enter Account Number: ";
            cin >> accNo;

            int index = findAccount(accounts, count, accNo);

            if (index != -1) {
                cout << "Enter New Name: ";
                cin >> newName;
                accounts[index].setHolderName(newName);
                cout << "Name updated.\n";
            } else {
                cout << "Account not found.\n";
            }
        }

        else if (choice == 3) {
            int fromAcc, toAcc;
            double amount;

            cout << "From Account: ";
            cin >> fromAcc;
            cout << "To Account: ";
            cin >> toAcc;
            cout << "Amount: ";
            cin >> amount;

            transferMoney(accounts, count, fromAcc, toAcc, amount);
        }

        else if (choice == 4) {
            for (int i = 0; i < count; i++) {
                accounts[i].display();
            }
        }

        else if (choice == 5) {
            cout << "Total Accounts Created: " << Account::totalAccounts << endl;
        }

    } while (choice != 0);

    delete[] accounts;

    return 0;
}


