#include <iostream>
using namespace std;

class Complex {
  private:
    double real, imag;
  public:
  // No parameters
  Complex() {
    real = 2;
    imag = 5;
    cout << "Creating a complex number with: " << endl;
    cout << "Real part: " << real << endl;
    cout << "Imaginary part: " << imag << endl;
  }
  // One parameter
  Complex(double value) {
    real = value;
    imag = value;
    cout << "Creating a complex number with: " << endl;
    cout << "Real part: " << real << endl;
    cout << "Imaginary part: " << imag << endl;
  }
  // Two parameter
  Complex(double t_real, double t_imag) {
    real = t_real;
    imag = t_imag;
    cout << "Creating a complex number with: " << endl;
    cout << "Real part: " << real << endl;
    cout << "Imaginary part: " << imag << endl;
  }
  friend Complex addTwo(Complex, Complex);
  friend void display(Complex);
};

Complex addTwo(Complex c1, Complex c2) {
  Complex c;
  c.real = c1.real + c2.real;
  c.imag = c1.imag + c2.imag;
  return c;
}

void display(Complex c) {
  cout << "******************" << endl << endl;
  cout << "Real part: " << c.real << endl;
  cout << "Imaginary part: " << c.imag << endl << endl;
  cout << "******************" << endl << endl;
}

int main() {
  Complex complex1;
  Complex complex2;
  addTwo(complex1, complex2);
  display(complex1);
  return 0;
}