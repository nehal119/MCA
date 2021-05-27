#include <iostream>
using namespace std;


int main() {
  string infix_str;
  cout << "Please enter the string" << endl;
  cin >> infix_str;
  for(int i = 0; i<infix_str.length(); i++) {
    cout << "“" << infix_str.at(i) << "“" << ", ";
  }
  cout << endl;
  return 0;
}