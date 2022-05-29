// Given a matrix if an element in the matrix is 0 then you will have to set its entire 
// column and row to 0 and then return the matrix.
#include <iostream>
using namespace std;

int main() {
  // Take n*m matrix
  int n = 3;
  int m = 3;
  int arr[n][m] = {{1,1,1},{1,0,1},{1,1,1}};
  /*
    [1,1,1]
    [1,0,1]
    [1,1,1]
  */
  // Scan item one by one and replace with zero, use brute force approach
  for (int i=0; i<n; i++) {
    for (int j=0; j<m;j++) {
      if (arr[i][j] == 0) {
        // Find current row number and make everyone in that row -1
        for (int k = 0; k < m; k++) {
          arr[i][k] = -1;
        }
        // Find current column number and make everyone in that column -1
        for (int k = 0; k < n; k++) {
          arr[k][j] = -1;
        }
      }
    }
  }
  // Now replace every -1 with 0
  for (int i=0; i<n; i++) {
    for (int j=0; j<m;j++) {
      if (arr[i][j] == -1) {
        arr[i][j] = 0;
      }
    }
  }
  // Print output
  for (int i=0; i<n; i++) {
    for (int j=0; j<m;j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}