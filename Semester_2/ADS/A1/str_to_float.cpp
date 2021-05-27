#include <iostream>

using namespace std;

float str_to_float(char * s){
  float rez = 0, fact = 1;
  if (*s == '-') {
    s++;
    fact = -1;
  };
  for (int point_seen = 0; *s; s++) {
    if (*s == '.'){
      point_seen = 1; 
      continue;
    };
    int d = *s - '0';
    if (d >= 0 && d <= 9){
      if (point_seen) fact /= 10.0f;
      rez = rez * 10.0f + (float)d;
    };
  };
  return rez * fact;
};

int main() {
  string str;
  cout << "Enter the string to convert: " << endl;
  cin >> str;

  char str_char[100];
  for (int i = 0; i < str.length(); i++) {
    cout << str.at(i) << endl;
    str_char[i] = str.at(i);
  }
  float num = str_to_float(str_char);
  cout << "Converted string is: " << num << endl;
  return 0;
}