#include <iostream>
using namespace std;

class BankAccount {
    private:
        double balance;
    public:
        BankAccount() { balance = 0.0; }
        void Deposit(double amount);
        void Withdraw(double amount);
        double GetBalance();
};

void BankAccount::Deposit(double amount) {
    balance += amount;
}

void BankAccount::Withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient funds." << endl;
    } else {
        balance -= amount;
    }
}

double BankAccount::GetBalance() {
    return balance;
}

int main()
{
    BankAccount myAccount;
    myAccount.Deposit(1000);
    cout << "Current Balance: " << myAccount.GetBalance() << endl;
    myAccount.Withdraw(500);
    cout << "Current Balance: " << myAccount.GetBalance() << endl;
    myAccount.Withdraw(600);
    cout << "Current Balance: " << myAccount.GetBalance() << endl;
    return 0;
}