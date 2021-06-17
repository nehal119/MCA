#include <iostream>

using namespace std;

class SquareMatrix {
  int a[10][10];
  int n;
  public:
    void read();
    void print();

    // Constructor
    SquareMatrix(int m) {
      n = m;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          a[i][j] = 0;
        }
      }
    }
};

void SquareMatrix::read() {
  cout << "Enter the values for the matrix";
  for (int i = 0; i < n; i++) {
    cout << "Matrix Row :" << i + 1 << endl;
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
}

void SquareMatrix::print() {
  cout << "The Resultant SquareMatrix is: \n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "  " << a[i][j];
    }
    cout << endl;
  }
}

int main() {
  int n;
  cout << "Enter order of the matrix: ";
  cin >> n;
  SquareMatrix x(n);
  x.read();
  x.print();
  return 0;
}