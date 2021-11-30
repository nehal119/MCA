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

  bubbleSort(arr, n);

  print(arr, n);
 
  return 0;
}