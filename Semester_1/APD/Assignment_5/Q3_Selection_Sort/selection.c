#include <stdio.h>
#include <time.h>

void looperFunc () {
  int n, i, temp, j;
  clock_t t;
  printf("Enter the length of array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter %d array items: \n", n);
  for(i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
  }
  t = clock();
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(arr[i]>arr[j]){
          temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
        }
    }
  }
  t = clock() - t; 
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  printf("\nSelection sort took %f seconds to complete \n", time_taken);
  printf("\nUsing Selection sort, the Sorted array is: \n");
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