/**
 * Name: Nehal Ahmad
 * Roll Number: 20MCA44
 */

#include <iostream>
using namespace std;

void print(int a[], int n) {
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << "  ";
  }
  cout << endl;
}

void segregateBubble(int a[], int n) {
  for (int step = 0; step < (n-1); ++step) {
    cout << "Step  " << step << endl;
    print(a, 8);
    for (int i = 0; i < n - (step-1); ++i) {
      // cout << "Loop  " << i << endl;
      // print(a, 8);
      if (a[i] < a[i + 1] && ((a[i] > 0 && a[i + 1] < 0) || (a[i] < 0 && a[i + 1] > 0))) {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    }
  }
}

int main() {

  int arr[] = {9, -3, 5, -2, -8, -6, 1, 3, 0}; // Why adding 0 to it ?
  // Output should be [9, 5, 1, 3, -3, -2, -8, -6]
  
  segregateBubble(arr, 8);
  
  cout << "Segregated array is:\n";  
  print(arr, 8);

  return 0;
}
