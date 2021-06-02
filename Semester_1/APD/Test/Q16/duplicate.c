#include <stdio.h>

// ARRAY SHOULD BE SORTED

int removeDuplicate(int arr[], int n) {
  if (n==0 || n==1)
    return n;

  int temp[n];

  int j = 0, i;

  for (i=0; i<n-1; i++)
    if (arr[i] != arr[i+1])
      temp[j++] = arr[i];

  temp[j++] = arr[n-1];

  for (i=0; i<j; i++)
    arr[i] = temp[i];

  return j;
}

void looperFunc () {
  int n, i;
  printf("Enter the length of array: ");
  scanf("%d",&n);
  int arr[n];

  printf("Enter %d items of array: \n", n);
  for(i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
  }

  n = removeDuplicate(arr, n);

  printf("The new Array is: \n");

  for (i = 0; i < n; i++)
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

// Time Complexity : O(n)