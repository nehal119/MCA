#include<iostream>
using namespace std;

class Student {
  private:
    int roll_number;
    string name, course;

  public:
    void input_student() {
      cout << "Enter student name: " << endl;
      cin >> name;
      cout << "Enter student course: " << endl;
      cin >> course;
      cout << "Enter student roll number: " << endl;
      cin >> roll_number;
    }
    void dislplay_student() {
      cout << "Student " << name << " admitted in " << course << " with roll number " << roll_number << endl;
    }
};

class Exam: public Student {
  private:
    float mark1, mark2, mark3;
  public: 
    void input_marks() {
      cout << "Enter Mark 1, 2 and 3: " << endl;
      cin >> mark1 >> mark2 >> mark3;
    }
    void display_result() {
      cout << "Marks in subjects 1,2,3 are: " << mark1 << " " << mark2 << " " << mark3 << endl;
    }
};

int main() {
  int n;
  cout << "Enter the number of students: " << endl;
  cin >> n;
  Exam exam[n];

  for(int i = 0; i < n; i++) {
    exam[i].input_student();
    exam[i].input_marks();
  }

  for(int i = 0; i < n; i++) {
    exam[i].dislplay_student();
    exam[i].display_result();
  }
}