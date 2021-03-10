#include <stdio.h>

void looperFunc () {
  int n, i, key, j;
  printf("Enter the length of array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter %d array items: \n", n);
  for(i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
  }
  for(i = 1; i < n; i++) {
    key = arr[i];
    j = i-1;

    while (j >= 0 && key < arr[j]) {
      arr[j+ 1] = arr[j];
      arr[j] = key;
      j--;
    }
  }
  printf("Using insertion sort, the Sorted array is: \n");
  for (i=0; i<n; i++)
    printf("%d ",arr[i]);
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}