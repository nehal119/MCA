#include <stdio.h>

// function to sum two matrices
void sumMatrices(int first[][100], int second[][100], int sum[][100], int r, int c) {

   // Initializing elements of matrix mult to 0.
   for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
         sum[i][j] = 0;
      }
   }

  // adding two matrices
  for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
          sum[i][j] = first[i][j] + second[i][j];
      }

}

// function to multiply two matrices
void multiplyMatrices(int first[][100], int second[][100], int result[][100], int r, int c) {

   // Initializing elements of matrix mult to 0.
   for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
         result[i][j] = 0;
      }
   }

   // Multiplying first and second matrices and storing it in result
   for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
         for (int k = 0; k < c; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}

// function to display the matrix
void display(int result[][100], int row, int column) {
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("%d  ", result[i][j]);
         if (j == column - 1)
            printf("\n");
      }
   }
}

void looperFunc () {
  int r, c, first[100][100], second[100][100], sum[100][100], result[100][100];
  printf("Enter the number of rows (between 1 and 100): ");
  scanf("%d", &r);
  printf("Enter the number of columns (between 1 and 100): ");
  scanf("%d", &c);

  printf("\nEnter elements of 1st matrix:\n");
  for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
          printf("Enter element a%d%d: ", i + 1, j + 1);
          scanf("%d", &first[i][j]);
      }

  printf("Enter elements of 2nd matrix:\n");
  for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
          printf("Enter element a%d%d: ", i + 1, j + 1);
          scanf("%d", &second[i][j]);
      }

  printf("\nSum is:\n");
  sumMatrices(first, second, sum, r, c);
  display(sum, r, c);

  printf("\nMultiplication is:\n");
  multiplyMatrices(first, second, result, r, c);
  display(result, r, c);
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}