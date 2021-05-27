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
      cout << "The resultant string after + overloading is: " << tmp << endl << endl;
    }
  
    void operator == (String& obj) {
      string str1, str2;
      str1 = convertToString(str, len);
      str2 = convertToString(obj.str, obj.len);

      int compare = str1.compare(str2);
      if (compare != 0) {
          cout << str1 << " is not equal to "<< str2 << endl;
      } else if(compare == 0){
          cout << "Strings are equal";
      }
    }

    void operator < (String& obj) {
      string str1, str2;
      str1 = convertToString(str, len);
      str2 = convertToString(obj.str, obj.len);

      int compare = str1.compare(str2);
      if (compare > 0) {
          cout << str1 << " is less than "<< str2 << endl;
      } else {
          cout << str1 << " is not less than "<< str2 << endl;
      }
    }

    void operator > (String& obj) {
      string str1, str2;
      str1 = convertToString(str, len);
      str2 = convertToString(obj.str, obj.len);

      int compare = str1.compare(str2);
      if (compare < 0){
        cout << str1 << " is greater than "<< str2 << endl;
      }
      else {
        cout << str1 << " is not greater than "<< str2 << endl;
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