#include <iostream>
using namespace std;

class Largest {
  public:
  double first;
  double second;
  double third;

  double findLargest() {
    if (first > second) {
      if (first > third) {
        return first;
      } else {
        return third;
      }
    } else if (second > third) {
      return second;
    } else {
        return third;
    }
  }
};

int main() {
  Largest largest;
  cout << "Enter first number: ";
  cin >> largest.first;
  cout << "Enter second number: ";
  cin >> largest.second;
  cout << "Enter third number: ";
  cin >> largest.third;

  cout << "The largest number is: " << largest.findLargest() << endl;

  return 0;
}