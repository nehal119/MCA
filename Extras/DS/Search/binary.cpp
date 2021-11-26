#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
  for (int i=0; i< n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int binarySearch(int arr[], int n, int key) {
  int s = 0, e = n;
  while (s <= e) {
    int mid = (s+e)/2;
    if (arr[mid] == key) {
      return mid;
    }
    else if (arr[mid] > key) {
      e = mid -1;
    }
    else {
      s = mid + 1;
    }
  }
  return -1;
}

int main() {
  int n, key;
  cin >> n;

  int arr[n];

  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }
  cout << "Enter key to search" << endl;
  cin >> key;

  cout << linearSearch(arr, n, key);
  cout << binarySearch(arr, n, key);

  return 0;
}