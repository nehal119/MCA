#include <iostream>

using namespace std;

class Polygon {
  protected:
    float width, height;
  public:
    void set_value(float width, float height) {
      this -> height = height;
      this -> width = width;
    }
  virtual void calculate_area() = 0;
};

// Inherit Rectangle from Polygon class
class Rectangle: public Polygon {
  public: void calculate_area() override {
    cout << "The area of the rectangle is: " << width * height << endl;
  }
};

// Inherit Triangle from Polygon class
class Triangle: public Polygon {
  public: void calculate_area() override {
    cout << "The area of the triangle is: " << width * height / 2 << endl;
  }
};

void looperFunc() {
  Rectangle rectangle;
  float width, height;
  cout << "Provide Rectangle width and height:" << endl;
  cin >> width;
  cin >> height;

  rectangle.set_value(width, height);

  Triangle triangle;
  cout << endl << "Provide Triangle width and height:" << endl;
  cin >> width;
  cin >> height;
  triangle.set_value(width, height);

  Polygon* p1;
  Polygon* p2;

  p1 = &rectangle;
  p2 = &triangle;

  p1 -> calculate_area();
  p2 -> calculate_area();

}

int main() {
  int cont = 1;
  while (cont != 0) {
    looperFunc();
    cout << endl << endl << "Enter 1 to continue and 0 to exit: ";
    cin >> cont;
  }
}