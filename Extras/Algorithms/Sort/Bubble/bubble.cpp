// https://www.geeksforgeeks.org/bubble-sort/
// https://www.geeksforgeeks.org/recursive-bubble-sort/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
  int temp;
  for(int i=0; i< n; i++){
    for(int j=0; j<n -1; j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void swap(int *x, int *y) {
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

void recursiveBubble(int arr[], int n) {
  if (n==1) {
    return;
  }
  for (int i=0; i<n-1; i++) {
    if(arr[i] > arr[i+1]) {
      swap(&arr[i], &arr[i+1]);
    }
  }
  recursiveBubble(arr, n-1);
}


void print(int arr[], int n) {
  cout << endl;
  for (int i=0; i< n; i++) {
    cout << arr[i] << "\t";
  }
  cout << endl;
}

int main() {
  int arr[] = {5, 1, 4, 2, 8};

  print(arr, 5);

  // bubbleSort(arr, n);
  recursiveBubble(arr, 5);

  print(arr, 5);
 
  return 0;
}