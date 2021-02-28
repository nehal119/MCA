#include <stdio.h>
#include <time.h>

void looperFunc () {
  int array[100], search, c, n;
  clock_t t;

  printf("Enter number of elements in array\n");
  scanf("%d", &n);

  printf("Enter %d integer(s)\n", n);

  for (c = 0; c < n; c++) {
    scanf("%d", &array[c]);
  }

  printf("Enter a number to search\n");
  scanf("%d", &search);

  // LINEAR SEARCH STARTED
  t = clock();
  for (c = 0; c < n; c++) {
    if (array[c] == search) {
      printf("\n\n%d found at location %d.\n", search, c+1);
      break;
    }
  }
  if (c == n) {
    printf("\n\n%d isn't present in the array.\n", search);
  }
  t = clock() - t; 
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  printf("\nLinear Search took %f seconds to complete \n", time_taken);


  // BINARY SEARCH STARTED
  t = clock();
  int first, last, middle;
  first = 0;
  last = n - 1;
  middle = (first+last)/2;

  while (first <= last) {
    if (array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      printf("\n\n%d found at location %d.\n", search, middle+1);
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    printf("\n\n%d isn't present in the array\n", search);
  t = clock() - t; 
  time_taken = ((double)t)/CLOCKS_PER_SEC;
  printf("\nBinary Search took %f seconds to complete \n", time_taken);

}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}