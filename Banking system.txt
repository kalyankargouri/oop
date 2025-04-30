#include <iostream>
#include <string>
using namespace std;

// Class to demonstrate function overloading
class Bank {
public:
    void deposit(int amount) {
        cout << "Depositing" << amount << " in cash." << endl;
    }

    void deposit(float amount) {
        cout << "Depositing" << amount << " via digital payment." << endl;
    }

    void deposit(string upiID) {
        cout << "Depositing amount using UPI (" << upiID << ")." << endl;
    }
};

// Class to demonstrate operator overloading
class Account {
private:
    int accountNumber;
    float balance;

public:
    Account(int accNum, float bal) : accountNumber(accNum), balance(bal) {}

    void display() {
        cout << "Account " << accountNumber << " Balance:" << balance << endl;
    }

    // Overloaded + operator to transfer funds between accounts
    void operator+(Account &acc) {
        float amount;
        cout << "Enter amount to transfer: ";
        cin >> amount;
        if (balance >= amount) {
            balance -= amount;
            acc.balance += amount;
            cout << "Transferring" << amount << " from Account " << accountNumber << " to Account " << acc.accountNumber << "..." << endl;
        } else {
            cout << "Insufficient balance for transfer!" << endl;
        }
    }

    // Overloaded - operator to withdraw funds
    void operator-(float amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawing " << amount << " from Account " << accountNumber << "..." << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

int main() {
    Bank bank;
    bank.deposit(5000);
    bank.deposit(1500.75f);
    bank.deposit("gpay@upi");

    cout << "\n";
    
    Account acc1(1, 10000);
    Account acc2(1, 5000);
    
    acc1.display();
    acc2.display();
    
    acc1 + acc2; // Transfer funds
    acc1.display();
    acc2.display();
    
    acc1 - 2000; // Withdraw funds
    acc1.display();

    return 0;
}
