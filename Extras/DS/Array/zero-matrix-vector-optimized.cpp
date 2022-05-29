// Given a matrix if an element in the matrix is 0 then you will have to set its entire 
// column and row to 0 and then return the matrix.
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Take n*m matrix vector
  vector < vector < int >> arr = {{1,1,1},{1,0,1},{1,1,1}};
  int rows = arr.size();
  int columns = arr[0].size();
  // Create two dummy arrays
  vector < int > dummy1(rows, -1), dummy2(columns, -1);
  /*
    [1,1,1]
    [1,0,1]
    [1,1,1]
  */
  // Insert 0 in dummy arrays
  for (int i=0; i<rows; i++) {
    for (int j=0; j < columns; j++) {
      if (arr[i][j] == 0) {
        dummy1[i] = 0;
        dummy2[j] = 0;
      }
    }
  }

  // Replace back dummy arrays data
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns;j++) {
      if (dummy1[i] == 0 || dummy2[j] == 0) {
        arr[i][j] = 0;
      }
    }
  }
  // Print output
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns;j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}