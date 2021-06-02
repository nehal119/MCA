#include <iostream>

using namespace std;

class A {
  private:
    int a;

  public:
    void set_a();
    void get_a();
    friend A operator * (A, A); //Binary operator * overloaded friend function, which takes two object of A and returns an object of A type.
};

//Definition of set_a() function
void A::set_a() {
  a = 5;
}

//Definition of get_a() function
void A::get_a() {
  cout << a << "\n";
}

//Definition of overloaded binary operator * friend function, which multiples two objects of A and returns an object of A
A operator * (A ob1, A ob2) {
  A temp;
  temp.a = ob1.a * ob2.a;
  return temp;
}

int main() {
  A ob1, ob2;
  ob1.set_a();
  ob2.set_a();

  cout << "The value of a in first object : ";
  ob1.get_a();

  cout << "The value of a in second object : ";
  ob2.get_a();

  //Calling operator overloaded friend function + to multiple two operands, objects
  A ob3 = ob1 * ob2; //ob1 and ob2 objects are passed as an argument to the operator * overloaded friend function.

  cout << "The value of a after calling operator overloading function * is : ";
  ob3.get_a();
}