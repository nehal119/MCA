#include <iostream>
using namespace std;

class Largest {
  private:
    string name, type_of_account;
    double account_number, balance;
  
  public:
    void assignInitials(string name_string, string type, double number, double bal) {
      name = name_string;
      account_number = number;
      type_of_account = type;
      balance = bal;
    }
    void deposite(double amount) {
      balance = balance + amount;
    }
    void withdraw(double amount) {
      if (amount > balance) {
        cout << "Not enough amount to withdraw";
      } else {
        balance = balance - amount;
      }
    }
    void display() {
      cout << "Name is: " << name << endl;
      cout << "Balance is: " << balance << endl;
    }
};

int main() {
  Largest largest;
  string name("Asif");
  string type_of_account("Savings");
  double account_number = 123456789;
  double balance = 100000;

  // Assign initials
  largest.assignInitials(name, type_of_account, account_number, balance);

  // Deposite an amount
  largest.deposite(5000);

  // Withdraw an amount
  largest.withdraw(1000);

  // Display the name and balance
  largest.display();

  return 0;
}