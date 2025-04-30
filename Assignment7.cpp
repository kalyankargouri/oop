#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;

public:
    BankAccount(string name, double bal) : ownerName(name), balance(bal) {}

    string getOwnerName() const {
        return ownerName;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Error: Invalid transaction!");
        }
        balance += amount;
        cout << "Depositing ?" << amount << " into " << ownerName << "'s Account" << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw runtime_error("Error: Insufficient funds!");
        }
        balance -= amount;
        cout << "Withdrawing: " << amount << " from " << ownerName << "'s Account" << endl;
    }

    void transfer(BankAccount &to, double amount) {
        if (amount > balance) {
            throw runtime_error("Error: Insufficient funds!");
        }
        balance -= amount;
        to.balance += amount;
        cout << "Transferring: " << amount << " from " << ownerName << " to " << to.ownerName << endl;
    }

    void divideBalance(double divisor) {
        if (divisor == 0) {
            throw runtime_error("Error: Cannot divide by zero!");
        }
        balance /= divisor;
        cout << "Dividing Balance by " << divisor << endl;
    }

    void display() {
        cout << "New Balance of " << ownerName << ": " << balance << endl;
    }
};

int main() {
    try {
        BankAccount b1("Rahul Sharma", 5000);
        cout << "Creating Account for " << b1.getOwnerName() << " with Initial Deposit:5000" << endl;

        b1.deposit(1000);
        b1.display();
        b1.withdraw(7000);
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    } catch (const runtime_error &e) {
        cout << e.what() << endl;
    }

    try {
        BankAccount b2("Priya Verma", 2000);

        BankAccount b1("Rahul Sharma", 3000);  
        b2.display();
        b1.transfer(b2, 3000);
        b1.display();
        b2.display();

        b1.divideBalance(0);
    } catch (const runtime_error &e) {
        cout << e.what() << endl;
    }

    return 0;
}

