#include <iostream>
using namespace std;

class EvenOdd {
   private:
    int number;

   public:

    // EvenOdd() : number(6) {}

    EvenOdd() {
      cout << endl << "Enter your number: ";
      cin >> number;
    }

    string operator ! () {
      // cout << "HI THERE";
      // !number;
      if (number % 2 == 0) {
        return "Even";
      } else {
        return "Odd";
      }
    }
};

void looperFunc() {
  EvenOdd EvenOdd1;
  cout << "The given number is: " << !EvenOdd1 << endl << endl;
}

int main() {
  int cont;
  while (cont != 0) {
    looperFunc();
    cout << "Enter 1 to continue and 0 to exit: ";
    cin >> cont;
  }
}