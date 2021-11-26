#include <iostream>
#include<string.h>
using namespace std;

class Person {
  private:
    string name;
    float weight, height;

  public:
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
	cout << endl << "Enter person's name: ";
  input >> p.name;

	cout << "Enter person's height (in meter): ";
	input >> p.height;

	cout << "Enter person's weight (in kg): ";
	input >> p.weight;

  return input;
}

ostream &operator << (ostream &output, Person &p) {
  char status[20];
  float bmi = p.getBMI();
	output << endl << "(Name: " << p.name << ","
			 << " weight: " << p.weight << ","
			 << " height: " << p.height << ","
			 << " BMI: " << bmi << ","
       << " BMI category: " << p.getBMICategory() << ")";
  return output;
}

void heap(Person arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
  
    if (l < n && arr[l].getBMI() > arr[largest].getBMI()){
      largest = l;
    }
    if (r < n && arr[r].getBMI() > arr[largest].getBMI()){
      largest = r;
    }
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heap(arr, n, largest);
    }
}

void heapSort(Person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--){
      heap(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heap(arr, i, 0);
    }
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
  cout << "Enter number of persons: ";
  cin >> n;
  Person arr[n];

  read(arr, n);
  cout << endl << "** Before Sort **";
  print(arr, n);

  heapSort(arr, n);
  cout << endl << "** After Sort **";
  print(arr, n);
  return 0;
}