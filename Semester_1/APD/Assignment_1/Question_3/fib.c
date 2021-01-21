#include <stdio.h>
#include <time.h>

int recCounter = 0;

int fibRec(int number) {
  recCounter += 1;
  if (number <= 1)
    return number;
  return fibRec(number - 1) + fibRec(number - 2); 
}

int fibItr(int number) {
  int a = 0, b = 1, c, i;
  if (number == 0)
      return a;
  for (i = 2; i <= number; i++) {
      c = a + b;
      a = b;
      b = c;
  }
  return b;
}

int main() { 
    int number;
    clock_t t;
    printf("Enter your number: ");
    scanf("%d", &number);

    t = clock();
    printf("\nFibonacci number using loop is: %d \n", fibItr(number)); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Loop took %f seconds to complete \n", time_taken);

    t = clock();
    printf("\nFibonacci number using recursion is: %d \n", fibRec(number));
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Recursion took %f seconds to complete \n", time_taken);
    printf("Number of function call is: %d \n", recCounter);
} 