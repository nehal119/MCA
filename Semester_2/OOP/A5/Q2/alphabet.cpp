#include<iostream>
#include<fstream>

using namespace std;

int main() {
  ifstream fin;
  fin.open("file1.txt");

  char str[100];
  int count = 0;

  cout << "***Displaying the lines not starting with A***" << endl << endl;
  while (!fin.eof()) {
    fin.getline(str, 100);
    if (str[0] != 'A') {
      count++;
      cout << str << endl;
    }
  }

  cout << endl << "Total number of lines are: " << count << endl;

  fin.close();
  return 0;
}