#include<iostream>
using namespace std;

class Student {
  private:
    int roll_number;
    string name;

  public:
    void get_details() {
      cout << "Enter student name: " << endl;
      cin >> name;
      cout << "Enter student roll number: " << endl;
      cin >> roll_number;
    }
    void display_details() {
      cout << "Student " << name << " with roll number " << roll_number << endl;
    }
};

class Examination: virtual public Student {
  private:
    float test1, test2;
  public:
    void get_test_score() {
      cout << "Enter score in test1: " << endl;
      cin >> test1;
      cout << "Enter score in test2: " << endl;
      cin >> test2;
    }
    float cal_average() {
      return (test1 + test2) / 2;
    }
    void display_average() {
      cout << "Marks in subjects 1,2,3 are: " << test1 << " " << test2 << endl;
    }
};

class Extracurricular: virtual public Student {
  protected:
    int painting, music;

  public:
    void get_score() {
      cout << "Enter score in painting: " << endl;
      cin >> painting;
      cout << "Enter score in music: " << endl;
      cin >> music;
    }
    void display_total() {
      cout << "Score in painting is " << painting << " and in music " << music << endl;
    }
};

class Result: public Examination, public Extracurricular {
  private:
    int total;

  public:
    void cal_total() {
      total = Examination::cal_average() + (painting + music ) / 2;
    }
    void comment() {
      cout << "Total marks are: " << total << endl;
      if (total > 40) {
        cout << "Passed!" << endl;
      } else {
        cout << "Failed!" << endl;
      }
    }
};

int main() {
  int n;
  cout << "Enter the number of students: " << endl;
  cin >> n;
  Result result[n];

  for(int i = 0; i < n; i++) {
    result[i].get_details();
    result[i].get_test_score();
    result[i].get_score();
  }

  for(int i = 0; i < n; i++) {
    result[i].cal_total();
    result[i].comment();
  }
}