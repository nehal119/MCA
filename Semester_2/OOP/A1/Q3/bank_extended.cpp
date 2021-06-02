#include <iostream>
#include <unistd.h>
using namespace std;

string gen_random(const int len) {
    string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    srand( (unsigned) time(NULL) * getpid());
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    return tmp_s; 
}

class Bank {
  private:
    string type_of_account, name, password;
    double balance;
    string account_number = gen_random(10);
  
  public:
    bool assigned = false;
    string username;
    void takeInputs() {
      string noUse;
      cout << "" << endl;
      getline( cin, noUse );
      cout << "Enter Name: " << endl;
      getline( cin, name );
      cout << "Enter Username: " << endl;
      getline( cin, username );
      cout << "Enter Password: " << endl;
      getline( cin, password );
      cout << "Enter Type Of Account: " << endl;
      getline( cin, type_of_account );
      // cout << "Enter Account Number: " << endl;
      // cin >> gen_random(5);
      cout << "Enter Balance: " << endl;
      cin >> balance;
      assigned = true;
    }
    int veryfyUser(string tusername, string tpassword) {
      if (tusername == username && tpassword == password) {
        return 1;
      } else {
        return 0;
      }
    }
    bool checkElem() {
      return assigned;
    }
    void deposite(double amount) {
      balance = balance + amount;
    }
    void withdraw(double amount) {
      if (amount > balance) {
        cout << "Not enough amount to withdraw" << endl;
      } else {
        balance = balance - amount;
      }
    }
    void display() {
      cout << "******************" << endl;
      cout << endl << endl;
      cout << "Name is: " << name << endl;
      cout << "Username is: " << username << endl;
      cout << "Balance is: " << balance << endl;
      cout << "Type of account is: " << type_of_account << endl;
      cout << "Account Number is: " << account_number << endl;
    }
};

Bank signupUser(Bank bank[], int i) {
  bank[i].takeInputs();
  return bank[i];
}

Bank loginUser(Bank bank[], int index) {
  int response;
  string tusername, tpassword;
  Bank signedInUser;
  string noUse;
  cout << "" << endl;
  getline( cin, noUse );
  cout << "Enter Username" << endl;
  getline( cin, tusername );
  cout << "Enter Password" << endl;
  getline( cin, tpassword );
  for (int i = 0; i < index; ++i) {
    response = bank[i].veryfyUser(tusername, tpassword);
    if (response == 1) {
      signedInUser = bank[i];
      break;
    }
  }
  return signedInUser;
}

int checkIndex(Bank bank[]) {
  int index = 0;
  for( int i=0; i < 10; i++ ) {
		if (!bank[i].checkElem()) {
      index = i;
      break;
    }
	}
  return index;
}

Bank userThere(Bank bank, int response) {
  double amount;
  switch (response){
  case 1:
    cout << "Please enter amount to withdraw" << endl;
    cin >> amount;
    bank.withdraw(amount);
    cout << "Account Updated" << endl;
    bank.display();
    break;
  case 2:
    cout << "Please enter amount to deposit" << endl;
    cin >> amount;
    bank.deposite(amount);
    cout << "Account Updated" << endl;
    bank.display();
    break;
  case 3:
    bank.display();
    break;
  case 4:
    break;
  default:
    cout << "Not a valid input, please retry";
    break;
  }
  return bank;
}

int showUserOptions(string username) {
  int response;
  cout << endl << "********* Welcome " << username << " *********" << endl << endl;;
  cout << "Press 1 to Withdraw money" << endl;
  cout << "Press 2 to Deposit money" << endl;
  cout << "Press 3 to Display Balance" << endl;
  cout << "Press 4 to visit main menu" << endl;
  cin >> response;
  cout << endl;
  return response;
}

Bank loginSuccess(Bank bank) {
  int response = 0;
  cout << endl << endl;
  response = showUserOptions(bank.username);
  while(response != 4) {
    bank = userThere(bank, response);
    response = showUserOptions(bank.username);
  }
  return bank;
}

void verifyUserAndServe(Bank bank[], int userInput) {
  int login = 0;
  Bank signedInUser;

  int index = checkIndex(bank);
  switch (userInput) {
    case 1:
      signedInUser = signupUser(bank, index);
      // login = 1;
      break;
    case 2:
      signedInUser = loginUser(bank, index);
      cout << "Login: " << login << "Index: " << index << endl;
      break;
    case 3:
      break;
    default:
      cout << "Not a valid input, please retry";
      break;
  }

  // if (login == 0) {
  //   cout << endl << "Username or password is incorrect, try again" << endl << endl;
  // } else {
    if (signedInUser.assigned) {
      cout << "Login Successfull" << endl << endl;
      // signedInUser = bank[index];
      bank[index] = loginSuccess(signedInUser);
    }
  // }
  return;

}

int showHomeOptions() {
  int userInput;
  cout << "********* Welcome to Your Bank *********" << endl << endl;;
  cout << "Press 1 to signup" << endl;
  cout << "Press 2 to login" << endl;
  cout << "Press 3 to exit" << endl;
  cin >> userInput;
  return userInput;
}

int main() {
  Bank bank[10];
  int userInput = 0;
  cout << endl << endl;
  userInput = showHomeOptions();
  while(userInput != 3) {
    verifyUserAndServe(bank, userInput);
    userInput = showHomeOptions();
  }
}
