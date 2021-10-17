/**
 * Name: Nehal Ahmad
 * Roll Number: 20MCA44
 */

#include <iostream>
using namespace std;

void sortSpecialSelection(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int diff = abs(a[i]);
    int j = i - 1;
    if (abs(a[j]) > diff) {
      int temp = a[i];
      while (abs(a[j]) > diff && j >= 0) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = temp;
    }
  }
}

void print(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << array[i] << "  ";
  }
  cout << endl;
}

int compute(int a[], int n) {
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    sum += abs(a[i] - a[i + 1]);
  }
  return sum;
}

int main() {
  int n, i;
  cout << "Enter the length of array: ";
  cin >> n;

  int arr[n];

  printf("Enter %d array items: \n", n);
  for(i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  cout << "The sum of absolute values is: " << compute(arr, n) << endl;

  sortSpecialSelection(arr, n);

  cout << "Sorted array is:\n";  
  print(arr, n);

  return 0;
}