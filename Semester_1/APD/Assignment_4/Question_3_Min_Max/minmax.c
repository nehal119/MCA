#include <stdio.h>

void looperFunc () {
  int array[100], search, n;

  printf("Enter number of elements in array\n");
  scanf("%d", &n);

  printf("Enter %d integer(s)\n", n);

  for (int c = 0; c < n; c++) {
    scanf("%d", &array[c]);
  }
  int min = array[0], max = array[0];
  printf("\n\nThe given array is: \n");
  for (int c = 0; c < n; c++) {
    if (array[c] < min) {
      min = array[c];
    }
    if (array[c] > max) {
      max = array[c];
    }
    printf("%d ", array[c]);
  }
  printf("\n\nmin-element is: %d \n max-element is: %d ", min, max);
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}