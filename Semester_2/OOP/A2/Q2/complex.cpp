#include <iostream>
using namespace std;

class Complex {
  private:

  public:
    float real;
    float imag;
    Complex() : real(0), imag(0) {}

    void input() {
        cout << "Enter real and imaginary parts respectively: ";
        cin >> real;
        cin >> imag;
    }

    Complex operator + (Complex obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

//   friend Complex operator + (Complex, Complex);

    void output() {
        if (imag < 0)
            cout << "Output Complex number: " << real << imag << "i" << endl;
        else
            cout << "Output Complex number: " << real << "+" << imag << "i" << endl;
    }
};

// Complex operator + (Complex obj1, Complex obj2) {
//     Complex temp;
//     temp.real = obj1.real + obj2.real;
//     temp.imag = obj1.imag + obj2.imag;
//     return temp;
// }

int main() {
    Complex complex1, complex2, result;

    cout << "Enter first complex number:\n";
    complex1.input();

    cout << "Enter second complex number:\n";
    complex2.input();

    result = complex1 + complex2;
    result.output();

    return 0;
}