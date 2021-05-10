#include <iostream>
using namespace std;

class Largest {
  private:
    string type_of_account, name, password;
    double account_number, balance;
    // bool assigned = false;
  
  public:
    bool assigned = false;
    string username;
    void takeInputs() {
      cout << "Enter Name: " << endl;
      getline( cin, name );
      cout << "Enter Username: " << endl;
      getline( cin, username );
      cout << "Enter Password: " << endl;
      getline( cin, password );
      cout << "Enter Type Of Account: " << endl;
      getline( cin, type_of_account );
      cout << "Enter Account Number: " << endl;
      cin >> account_number;
      cout << "Enter Balance: " << endl;
      cin >> balance;
      assigned = true;
    }
    int veryfyUser() {
      string tusername, tpassword;
      cout << "Enter Name" << endl;
      getline( cin, tusername );
      cout << "Enter Username" << endl;
      getline( cin, tpassword );
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
        cout << "Not enough amount to withdraw";
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

void signupUser(Largest largest[], int i) {
  largest[i].takeInputs();
}

int loginUser(Largest largest[], int i) {
  int count = 0, response;
  while (count < 3 && response == 0 ) {
    cout << "Username or password is incorrect, try again!!!" << endl;
    response = largest[i].veryfyUser();
    if (response == 1) {
      break;
    }
    count += 1;
  }
  return response;
}

int checkIndex(Largest largest[]) {
  int index = 0;
  for( int i=0; i < 10; i++ ) {
		if (!largest[i].checkElem()) {
      index = i;
      break;
    }
	}
  return index;
}
void userThere(Largest largest, int response) {
    double amount;
  switch (response){
  case 1:
    cout << "Please enter amount" << endl;
    cin >> amount;
    largest.withdraw(amount);
    break;
  case 2:
    cout << "Please enter amount" << endl;
    cin >> amount;
    largest.deposite(amount);
    break;
  case 3:
    largest.display();
    break;
  case 4:
    break;
  default:
    cout << "Not a valid input, please retry";
    break;
  }
}
void loginSuccess(Largest largest) {
  int response = 0;
  cout << endl << endl;
  cout << "********* Welcome " << largest.username << " *********" << endl << endl;;
  cout << "Press 1 to Withdraw money" << endl;
  cout << "Press 2 to Deposit money" << endl;
  cout << "Press 3 to Display Balance" << endl;
  cout << "Press 4 to visit main menu" << endl;
  cin >> response;
  cout << endl;
  while(response != 4) {
    userThere(largest, response);
  }
  return;
}

void verifyUserAndServe(Largest largest[], int userInput) {
  int login = 0;
  Largest signedInUser;

  int index = checkIndex(largest);
  switch (userInput) {
    case 1:
      signupUser(largest, index);
      login = 1;
      break;
    case 2:
      login = loginUser(largest, index);
      break;
    case 3:
      break;
    default:
      cout << "Not a valid input, please retry";
      break;
  }

  if (login == 0) {
    cout << "You have exceeded maximum attempts, please try after some time" << endl;;
  } else {
    cout << "Login Successfull" << endl << endl;
    signedInUser = largest[index];
    loginSuccess(signedInUser);
  }
  return;

}

int main() {
  Largest largest[10];
  int userInput = 0;
  cout << "********* Welcome to New Wells Bank *********" << endl << endl;;
  cout << "Press 1 to signup" << endl;
  cout << "Press 2 to login" << endl;
  cout << "Press 3 to exit" << endl;
  cin >> userInput;
  cout << endl << endl;
  while(userInput != 3) {
    verifyUserAndServe(largest, userInput);
  }
}
