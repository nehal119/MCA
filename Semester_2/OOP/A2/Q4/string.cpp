#include <iostream>
#include <cstring>
using namespace std;

string convertToString(char* a, int size) {
  int i;
  string s = "";
  for (i = 0; i < size; i++) {
    s = s + a[i];
  }
  return s;
}

int compareASCII(char* str1, int size1, char* str2, int size2) {
  int size = size1, flag = 0;
  if (size2 < size1) {
    size = size2;
  }
  for (int i = 0; i < size; i++) {
    if ((int)str1[i] > (int)str2[i]) {
      flag = 1;
      break;
    } else if ((int)str1[i] < (int)str2[i]) {
      flag = 2;
      break;
    }
  }
  return flag;
}

class String {
  private:
    int len;
    char str[100];

  public:

    String() : str() {}

    void getdata() {
      cout << "Enter string length: " << endl;
      cin >> len;
      cout << "Enter your string: " << endl;
      cin >> str;
    }
    void show() {
      cout <<"******************************" << endl << endl;
      cout << "Given string is:" << str << endl;
      cout << "Given string length is:" << len << endl;
      cout <<"******************************" << endl << endl;
    }

    void operator + (const String& obj) {
      char tmp[100];
      strcpy(tmp, str);
      strcat(tmp, obj.str);
      cout << "The resultant after concatenation is: " << tmp << endl << endl;
    }
  
    void operator == (String& obj) {
      int response = compareASCII(str, len, obj.str, obj.len);
      if (response == 0) {
        // cout << obj.str << " is equals to "<< str << endl;
        cout << str << " equals to "<< obj.str << " true" << endl;
      } else {
        cout << str << " equals to "<< obj.str << " false" << endl;
      }
    }

    void operator < (String& obj) {
      int response = compareASCII(str, len, obj.str, obj.len);
      if (response == 1) {
        cout << str << " greater than "<< obj.str << " true" << endl;
      } else {
        cout << str << " greater than "<< obj.str << " false" << endl;
      }
    }

    void operator > (String& obj) {
      int response = compareASCII(str, len, obj.str, obj.len);
      if (response == 2) {
        cout << str << " less than "<< obj.str << " true" << endl;
      } else {
        cout << str << " less than "<< obj.str << " false" << endl;
      }
    }
};

int main() {
  String str1, str2, result;

  cout << "***Enter first string***" << endl;
  str1.getdata();
  str1.show();

  cout << "***Enter second string***" << endl;
  str2.getdata();
  str2.show();

  str1 + str2;

  (str1 == str2);

  (str1 < str2);

  (str1 > str2);

  return 0;
}