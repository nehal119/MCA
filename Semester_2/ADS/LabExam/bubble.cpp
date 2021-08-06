// NEHAL AHMAD

#include<iostream>
using namespace std;

void swap(int & a, int & b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void display(int * array, int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

void partitionBubbleSort(int * array, int n) {
  for (int i = 0; i < n; i++) {
    int swapped = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
        swapped = 1;
      }
    }
    if (!swapped)
      break;
  }
}

int main() {
  int n;
  cout << "Enter array length: ";
  cin >> n;
  int arr[n];
  cout << "Enter elements:" << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "Before Sorting: ";
  display(arr, n);

  partitionBubbleSort(arr, n);

  cout << "After Sorting: ";
  display(arr, n);
}