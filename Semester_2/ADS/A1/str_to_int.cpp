#include <iostream>

using namespace std;

// Converts char[] into int
int char_to_int(char * str) {
  int nb;
  int sign;
  int i;

  nb = 0;
  sign = 0;
  i = -1;
  if (!str)
    return (0);
  while (str[++i])
    if (str[i] < '0' && str[i] > '9' && str[i] != '-' && str[i] != '+')
      return (0);
  i = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    if (str[i++] == '-')
      ++sign;
  while (str[i] && (str[i] >= '0' && str[i] <= '9')) {
    nb = (nb * 10) + (str[i++] - '0');
    if (str[i] == ' ')
      i++;
  }
  return (((sign % 2) == 1) ? ((nb) * (-1)) : (nb));
}

// Converts string into int, works only for positive integers
int str_to_int(string str) {
  int temp = 0;
  for (int i = 0; i < str.length(); i++) {
    temp = temp * 10 + (str[i] - '0'); // Since ASCII value of character from '0' to '9' are contiguous. So if we subtract '0' from ASCII value of a digit, we get the integer value of the digit.
  }
  return temp;
}

int main() {
  string str;
  cout << "Enter the string to convert: " << endl;
  cin >> str;
  // int num = str_to_int(str);

  char str_char[100];
  for (int i = 0; i < str.length(); i++) {
    str_char[i] = str.at(i);
  }
  int num = char_to_int(str_char);
  cout << "Converted string is: " << num << endl;
  return 0;
}