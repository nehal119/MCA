#include<iostream>
using namespace std;

struct StudentData {
  int stud_roll;
  string stud_name, course_name, dob;
};

struct ExamData {
  int marks_obtained, total_marks;
  string exam_name, paper_name, paper_code, grades;
};

typedef struct StudentData Struct1;
typedef struct ExamData Struct2;


class Exam {
  private: 
    int marks_obtained, total_marks;
    string exam_name, paper_name, paper_code, grades;

  public:
    void load() {
      cout << "Enter exam name:";
      cin >> exam_name;
      cout << "Enter paper name:";
      cin >> paper_name;
      cout << "Enter student paper code:";
      cin >> paper_code;
      cout << "Enter student marks obtained:";
      cin >> marks_obtained;
      cout << "Enter student total marks:";
      cin >> total_marks;
      cout << "Enter student grades:";
      cin >> grades;
    }
    Struct2 getmarks() {
      Struct2 exam;
      exam.exam_name = exam_name;
      exam.paper_name = paper_name;
      exam.marks_obtained = marks_obtained;
      exam.total_marks = total_marks;
      exam.paper_code = paper_code;
      exam.grades = grades;
      return exam;
    }
    void printresult() {
      cout << endl << "========================" << endl;
      cout << "Exam Name: " << exam_name << endl;
      cout << "Paper Name: " << exam_name << endl;
      cout << "Paper Code: " << paper_code << endl;
      cout << "Grades: " << grades << endl;
      cout << "Marks Obtained: " << marks_obtained << endl;
      cout << "Total Marks: " << total_marks << endl;
    }
    void modifymarks(int emarks_obtained, int etotal_marks, string eexam_name, string epaper_name, string epaper_code, string egrades) {
      exam_name = eexam_name;
      paper_name = epaper_name;
      paper_code = epaper_code;
      grades = egrades;
      marks_obtained = emarks_obtained;
      total_marks = etotal_marks;
    }
};

class Student {
  private: 
    int stud_roll;
    string stud_name, course_name, dob;

  public:
    static int studentCount;
    Exam exam;

    void load() {
      cout << "Enter student roll no.: ";
      cin >> stud_roll;
      cout << "Enter student name: ";
      cin >> stud_name;
      cout << "Enter student course name: ";
      cin >> course_name;
      cout << "Enter student DOB: ";
      cin >> dob;
      ++studentCount;
    }
    Struct1 getrec() {
      Struct1 student;
      student.stud_roll = stud_roll;
      student.stud_name = stud_name;
      student.course_name = course_name;
      student.dob = dob;
      return student;
    }
    void printrec() {
      cout << endl << "========================" << endl;
      cout << "Student Roll Number: " << stud_roll << endl;
      cout << "Student Name: " << stud_name << endl;
      cout << "Student Course Name: " << course_name << endl;
      cout << "Student DOB: " << dob << endl;
    }
    void modifyrec(int sstud_roll, string sname, string scourse_name, string sdob) {
      stud_roll = sstud_roll;
      stud_name = sname;
      course_name = scourse_name;
      dob = sdob;
    }
};

int Student::studentCount = 0;

int main() {
  int n;
  cout << "Enter the number of students: ";
  cin >> n;
  Student students[n];
  for (int i = 0; i < n; i++) {
    students[i].load();
    students[i].printrec();
    students[i].exam.load();
    students[i].exam.printresult();
  }

  return 0;
}
