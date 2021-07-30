#include<iostream>


using namespace std;

class Student {
  protected:
    char name[20], department[20];
  public:
    virtual void get_data() = 0;
    virtual void show_data() = 0;
};

class Engineering: public Student {
  public:
    void get_data() {
      cout << "\nEnter the name of the Engineering Student: ";
      cin >> name;
      cout << "Enter Department: ";
      cin >> department;
    }
    void show_data() {
      cout << "\nThe Information of Engineering student is ";
      cout << "\nName : " << name;
      cout << "\nDepartment: " << department;
    }
};

class Medicine: public Student {
  public:
    void get_data() {
      cout << "Enter the name of the Medicine student ";
      cin >> name;
      cout << "Enter Department: ";
      cin >> department;
    }
    void show_data() {
      cout << "\nThe information of Medicine student is ";
      cout << "\nName: " << name;
      cout << "\n Department: " << department;
    }
};

class Science: public Student {
  public:
    void get_data() {
      cout << "\nEnter the name of the Science Student: ";
      cin >> name;
      cout << "Enter Department: ";
      cin >> department;
    }
    void show_data() {
      cout << "\nThe informaion of Science student is ";
      cout << "\nName: " << name;
      cout << "\nDepartment: " << department;
    }
};

int main() {
  Student * stu[3];
  stu[0] = new Engineering;
  stu[1] = new Medicine;
  stu[2] = new Science;
  for (int i = 0; i < 3; i++) {
    stu[i] -> get_data();
  }
  for (int i = 0; i < 3; i++) {
    stu[i] -> show_data();
  }
  return 0;
}