#include<iostream>
using namespace std;

class Student {
  private: 
    string name;
    float marks;
    string grade;

  public:
    static int studentCount;

    Student(string sname, float smarks, string sgrade) {
      name = sname;
      marks = smarks;
      grade = sgrade;
      ++studentCount;
    }

    void display() {
      cout << endl << "========================" << endl;
      cout << "Student Name: " << name << endl;
      cout << "Student Marks: " << marks << endl;
      cout << "Student Grade: " << grade << endl;
    }
};

int Student::studentCount = 0;

int main() {
  Student student1("John", 77, "B");
  Student student2("Jack", 86, "A");

  student1.display();
  student2.display();

  cout << endl << endl;
  cout << "The total number of students are: " << Student::studentCount << endl;

  return 0;

}
