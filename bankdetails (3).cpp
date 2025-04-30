#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    string accountType;
    double balance;

public:
    BankAccount() {
        accountHolder = "Unknown";
        accountNumber = 0;
        accountType = "Savings";
        balance = 0;
    }

    BankAccount(string holder, int number, string type, double bal) {
        accountHolder = holder;
        accountNumber = number;
        accountType = type;
        balance = bal;
    }

    string getAccountHolder(){ 
		return accountHolder;
	}
    int getAccountNumber(){ 
		return accountNumber; 
	}
    string getAccountType(){
   		 return accountType;
    }
    double getBalance(){
		 return balance;
	 }

    void setAccountType(string newType){
		 accountType = newType; 
    }

    void deposit(double amount) {
            balance=balance+amount;
            cout << "Depositing " << amount << "\nNew Balance: " << balance << endl;
    }

    void withdraw(double amount) {
            balance=balance-amount;
            cout << "Withdrawing " << amount << "\nNew Balance: " << balance << endl;
        
    }

    void displayAccountDetails() {
        cout << "Account Details:\n";
        cout << "Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: " << balance << "\n" << endl;
    }
};

int main() {
    BankAccount acc1("Gouri sandesh kalyankar ", 123456, "Savings", 5000);
    BankAccount acc2;
    acc1.displayAccountDetails();
    
    acc1.deposit(2000);
    acc1.withdraw(1500);
    
    acc1.setAccountType("Current");
    cout << "Updated Account Type to Current.\n";
    
    cout << "Final Account Details:" << endl;
    acc1.displayAccountDetails();

    return 0;
}
