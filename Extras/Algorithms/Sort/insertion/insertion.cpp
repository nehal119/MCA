// https://www.geeksforgeeks.org/insertion-sort/

#include <iostream>
using namespace std;

void sort(int arr[], int n) {
  int i, j, key;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

int main() {
  int arr[] = {5,1,4,2,8};

  sort(arr, 5);

  for (int i=0; i< 5; i++){
    cout << arr[i] << '\t';
  }
  cout << endl;
  return 0;
}