/**
 * Name: Nehal Ahmad
 * Roll Number: 20MCA44
 * TIME COMPLEXITY IN THE BEST CASE: O(1)
 * TIME COMPLEXITY IN THE WORST CASE: O(n)
 */

#include <iostream>
using namespace std;

void segregateBubble(int arr[], int n) {
  int countNegative = 0;  // To count the negative numbers
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      countNegative++;
    }
  }
  // Run a loop until all negative
  // numbers are moved to the beginning
  int i = 0, j = i + 1;
  while (i != countNegative) {
    // If number is negative, update
    // position of next positive number.
    if (arr[i] < 0) {
      i++;
      j = i + 1;
    }

    // If number is positive, move it to
    // index j and increment j.
    else if (arr[i] > 0 && j < n) {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

int main() {
  // int countNegative = 0;
  int arr[] = {9, -3, 5, -2, -8, -6, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  segregateBubble(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}