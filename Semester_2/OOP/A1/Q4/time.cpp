#include <iostream>
#include <ctime>
using namespace std;

class Time {
  private:
    time_t now;

  public:
    tm *ltm;
    void input() {
      now = time(0);
      ltm = localtime(&now);
    }
    void gettime() {
      cout <<"******************************" << endl << endl;
      cout << "Enter Hours: " << endl;
      cin >> ltm -> tm_hour;
      cout << "Enter Minutes: " << endl;
      cin >> ltm -> tm_min;
      cout <<"******************************" << endl << endl;
    }
    void display() {
      cout <<"******************************" << endl << endl;
      cout << "Year:" << 1900 + ltm -> tm_year << endl;
      cout << "Month: "<< 1 + ltm -> tm_mon << endl;
      cout << "Day: "<< ltm -> tm_mday << endl;
      cout << "Time: "<< ltm -> tm_hour << ":";
      cout << ltm -> tm_min << ":";
      cout << ltm -> tm_sec << endl;
      cout <<"******************************" << endl << endl;
    }
};

Time add(Time time1, Time time2) {
  Time time;
  int hours, minutes;
  hours = time1.ltm -> tm_hour + time2.ltm -> tm_hour;
  minutes = time1.ltm -> tm_min + time2.ltm -> tm_min;
  if (minutes > 60) {
    ++hours;
    minutes = 0;
  }
  time1.ltm -> tm_hour = hours;
  time1.ltm -> tm_min = minutes;
  return time;
}

int main() {
  Time time;
  time.input();
  time.display();
  time.gettime();
  time.display();
  return 0;
}