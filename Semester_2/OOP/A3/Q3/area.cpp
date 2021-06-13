#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
using namespace std;

class Shape {
  private: 

  public:
    float traingle_base, traingle_height;
    float rectangle_length, rectangle_width;
    float circle_radius;

    // Taking input using constructor 
    Shape() {
      cout << "Enter traingle base: " << endl;
      cin >> traingle_base;
      cout << "Enter traingle height: " << endl;
      cin >> traingle_height;
      cout << "Enter rectangle length: " << endl;
      cin >> rectangle_length;
      cout << "Enter rectangle width: " << endl;
      cin >> rectangle_width;
      cout << "Enter circle radius: " << endl;
      cin >> circle_radius;
    }
  
    // Calculate Area of Triangle
    float calculate_area(float b, float h, float factor) {
      return b * h / factor;
    }

    // Calculate Area of Rectangle
    float calculate_area(float w, float l) {
      return w * l;
    }

    // Calculate Area of Circle
    float calculate_area(float r) {
      return M_PI * pow(r, 2);
    }
};

void looperFunc() {
  Shape shape;
  cout << endl << endl;
  cout << "Area of Triangle is: " << shape.calculate_area(shape.traingle_base, shape.traingle_height, 2) << endl << endl;
  cout << "Area of Rectangle is: " << shape.calculate_area(shape.rectangle_width, shape.rectangle_length) << endl << endl;
  cout << "Area of Circle is: " << shape.calculate_area(shape.circle_radius) << endl << endl;
}

int main() {
  int cont = 1;
  while (cont != 0) {
    looperFunc();
    cout << "Enter 1 to continue and 0 to exit: ";
    cin >> cont;
  }
}