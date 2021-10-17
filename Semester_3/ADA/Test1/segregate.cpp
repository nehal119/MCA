/**
 * Name: Nehal Ahmad
 * Roll Number: 20MCA44
 */

#include <iostream>
using namespace std;

void segregateBubble(int a[], int n) {
  for (int step = 0; step < (n-1); ++step) {
      for (int i = 0; i < n - (step-1); ++i) {
      if (a[i] > a[i + 1] && ((a[i] > 0 && a[i + 1] < 0) || (a[i] < 0 && a[i + 1] > 0))) {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    }
  }
}

void print(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << a[i] << "  ";
  }
  cout << endl;
}

int main() {
  int n, i;
  cout << "Enter the length of array: ";
  cin >> n;

  int arr[n];

  printf("Enter %d array items: \n", n);
  for(i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
  }
  
  segregateBubble(arr, n);
  
  cout << "Segregated array is:\n";  
  print(arr, n);

  return 0;
}

/**
 * TIME COMPLEXITY IN THE BEST CASE: O(n)
 * TIME COMPLEXITY IN THE WORST CASE: O(n*n) when array is reverse sorted
 */