#include <stdio.h>
#include <time.h>

void quicksort(int arr[100],int start,int end){
   int i, j, pivot, temp;
   if(start<end){
      pivot=start;
      i=start;
      j=end;
      while(i<j){
         while(arr[i]<=arr[pivot]&&i<end)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,start,j-1);
      quicksort(arr,j+1,end);

   }
}

void looperFunc () {
  int n, i;
  clock_t t;
  printf("Enter the length of array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter %d array items: \n", n);
  for(i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
  }
  t = clock();
  quicksort(arr,0,n-1);
  t = clock() - t; 
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  printf("\nQuick sort took %f seconds to complete \n", time_taken);
  printf("\nUsing Quick sort, the Sorted array is: \n");
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