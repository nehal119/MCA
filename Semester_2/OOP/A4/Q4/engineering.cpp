#include <iostream>

using namespace std;

class student {
  public:
    virtual void getdata() = 0;
    virtual void display() = 0;
};

class engineering: public student {
  int r;
  char n[10];
  public:
    void getdata() {
    cout << "faculty->Engineering" << endl;
    cout << "enter name";
    cin >> n;
    cout << "enter roll";
    cin >> r;
  }

  void display() {
    cout << endl << "name=" << n;
    cout << endl << "roll=" << r << endl << endl;
  }
};

class medicine: public student {
  int r;
  char n[10];
  public:
    void getdata() {
    cout << "Faculty->Medicine";
    cout << endl << "enter name";
    cin >> n;
    cout << "enter roll";
    cin >> r;
  }
  void display() {
    cout << endl << "name=" << n;
    cout << endl << "roll=" << r << endl << endl;
  }
};

class science: public student {
  int r;
  char n[10];
  public:
    void getdata() {
    cout << "Faculty->Science";
    cout << endl << "enter name";
    cin >> n;
    cout << "enter roll";
    cin >> r;
  }
  void display() {
    cout << endl << "name=" << n;
    cout << endl << "roll=" << r << endl << endl;
  }
};

int main() {
  student * ptr[3];
  engineering e;
  medicine m;
  science s;
  ptr[0] = & e;
  ptr[0] -> getdata();
  ptr[0] -> display();
  ptr[1] = & m;
  ptr[1] -> getdata();
  ptr[1] -> display();
  ptr[2] = & s;
  ptr[2] -> getdata();
  ptr[2] -> display();
  return 0;
}