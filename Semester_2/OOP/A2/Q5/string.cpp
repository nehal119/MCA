#include <iostream>
#include <cstring>
using namespace std;

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
      cout << "The resultant string after + overloading is: " << tmp << endl;
    }
  
    // string operator < (const String& obj) {
    //   if((str.compare(obj.str)) < 0)
    //       cout << s1 << " is smaller than " << s2 << endl;
    //   }

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

  // (str1 == str2)

  // (str1 < str2)

  // (str1 > str2)

  return 0;
}