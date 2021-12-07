// https://www.geeksforgeeks.org/selection-sort/

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j=i+1; j<n; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        exit;
      }
    }
  }
}

void print(int arr[], int n) {
  cout << endl;
  for (int i=0; i< n; i++) {
    cout << arr[i] << "\t";
  }
  cout << endl;
}

int main() {
  int n; cin >> n;
  int arr[n];
  for (int i=0; i< n; i++) {
    cin >> arr[i];
  }

  print(arr, n);

  selectionSort(arr, n);

  print(arr, n);
 
  return 0;
}