#include <iostream>
#include<string.h>
using namespace std;

class Person {
  private:
    string name;
    float weight, height;

  public:

    // Person() : feet(0), inches(0) {}

    float getBMI() {
      return weight / (height * height);
    }
    string getBMICategory() {
      float bmi = weight / (height * height);
      if (bmi < 18.50) {
        return "Underweight";
      } else if (bmi <= 24.99) {
        return "Normal";
      } else if (bmi <= 29.99) {
        return "Overweight";
      } else {
        return "Obese";
      }
    }
    friend istream &operator >> (istream &input, Person &p);
		friend ostream &operator << (ostream &output, Person &p);
    bool operator < (Person person) {
      return getBMI() < person.getBMI();
    }
    bool operator >= (Person person) {
      return getBMI() >= person.getBMI();
    }
};

istream &operator >> (istream &input, Person &p){
	cout << endl << "Enter Name:\t";
	// getline(input, p.name);
  input >> p.name;
	cout << "Enter height:\t";
	input >> p.height;

	cout << "Enter weight:\t";
	input >> p.weight;
  return input;
}

ostream& operator << (ostream &output, Person &p) {
  char status[20];
  float bmi = p.getBMI();
  // strcpy(status, p.getBMICategory());
	output << endl << "NAME = " << p.name << endl
			 << "Weight = " << p.weight
			 << "kg" << endl
			 << "Height = " << p.height << " cm" << endl
			 << "BMI = " << bmi << "(" << p.getBMICategory() << ")";
  return output;
}

void read(Person arr[], int n) {
  for(int i=0; i< n; i++) {
    cin >> arr[i];
  }
}
void print(Person arr[], int n) {
  for(int i=0; i< n; i++) {
    cout << arr[i];
  }
}
int main() {
  int n, i;
  cout << "Enter number of students: ";
  cin >> n;
  Person arr[n];
  read(arr, n);
  print(arr, n);
  return 0;
}