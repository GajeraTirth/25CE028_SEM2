#include<iostream>
#include <string>
using namespace std;

    class BankAccount
    {
        private:
            string accountHoldername;
            int accountnumber;
            double balance;

        public:
            BankAccount(string name,int accno,double initialbalance)
            {
                accountHoldername=name;
                accountnumber=accno;
                balance=initialbalance;
            }
        void deposit(double amount)
        {
            if(amount>0)
            {
                balance+=amount;
                cout<<"Amount deposited successfully."<<endl;
            }
            else
            {
                cout<<"Invalid deposit amount."<<endl;
            }
        }
        void withdraw(double amount)
        {
            if(amount<=balance)
            {
                balance-=amount;
                cout<<"Error: Insufficient balance."<<endl;
            }
        }
        double getBalance()
        {
            return balance;
        }
        void displayAccountDetails()
        {
            cout<<"Account Holder Name: "<< accountHoldername<<endl;
            cout<<"Account Number: "<< accountnumber<<endl;
            cout<<"Account Balance: "<<balance<<endl;
        }
    };

int main()
{
    BankAccount acc1("Mithil patel",101234,5000);

    acc1.displayAccountDetails();
    acc1.deposit(2000);
    acc1.withdraw(3000);
    acc1.withdraw(6000);

    cout<<"Final Balance: "<<acc1.getBalance()<<endl;
    return 0;
}









