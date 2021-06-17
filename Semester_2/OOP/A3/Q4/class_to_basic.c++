#include<iostream>
using namespace std;

class Distance {
  int feet, inches;
  public:
    Distance(int, int);
    operator float();
};

// Calling default constructor
Distance::Distance(int a, int b) {
  feet = a;
  inches = b;
}

// Converting class into type
Distance::operator float() {
  return (feet * 0.3048 + inches * 0.0254);
}

int main() {
  int feet, inch;
  float distance;
  cout << "Enter Feet: ";
  cin >> feet;
  cout << "Enter Inches: ";
  cin >> inch;
  Distance d(feet, inch);
  distance = d;
  cout << "Total distance in meters are " << distance << endl;

  return 0;
}