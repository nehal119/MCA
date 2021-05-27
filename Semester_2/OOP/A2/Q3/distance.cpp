#include <iostream>
using namespace std;

class Distance {
  private:
    float feet;
    float inches;

  public:

    Distance() : feet(0), inches(0) {}

    // // Two parameter constructor
    // Distance(double t_feet, double t_inches) {
    //   feet = t_feet;
    //   inches = t_inches;
    //   cout << "Creating a distance with: " << endl;
    //   cout << "Feet: " << feet << endl;
    //   cout << "Inches: " << inches << endl;
    // }

    void getdata() {
      int t_feet, t_inches;
      cout << "Enter Feet: " << endl;
      cin >> t_feet;
      cout << "Enter Inches: " << endl;
      cin >> t_inches;
      while (t_inches >= 12) {
        t_feet += 1;
        t_inches -= 12;
      }
      feet = t_feet;
      inches = t_inches;
    }
    void show() {
      cout <<"******************************" << endl << endl;
      cout << "Feets:" << feet << endl;
      cout << "Inches: "<< inches << endl;
      cout <<"******************************" << endl << endl;
    }
    void operator < (const Distance& obj) {
      if (obj.feet > feet) {
        cout << "Second distance is larger" << endl;
      } else if (obj.feet < feet) {
        cout << "First distance is larger" << endl;
      } else {
        if (obj.inches > inches) {
          cout << "Second distance is larger" << endl;
        } else {
          cout << "First distance is larger" << endl;
        }
      }
    }
    Distance operator += (const Distance& obj) {
      Distance temp;
      temp.feet = feet + obj.feet;
      temp.inches = inches + obj.inches;
      while (temp.inches >= 12) {
        temp.feet += 1;
        temp.inches -= 12;
      }
      return temp;
    }
};

int main() {
  Distance distance1, distance2, result;

  cout << "Enter first distance:\n";
  distance1.getdata();
  distance1.show();

  cout << "Enter second distance:\n";
  distance2.getdata();
  distance2.show();

  distance1 < distance2;

  result = distance1 += distance2;

  result.show();

  return 0;
}