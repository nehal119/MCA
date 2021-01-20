#include <stdio.h>

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
    printf("Enter your number: ");
    scanf("%d", &number);
    printf("Fibonacci number using loop is: %d \n", fibItr(number)); 
    printf("Fibonacci number using recursion is: %d \n", fibRec(number));
    printf("Number of function call is: %d \n", recCounter);
} 