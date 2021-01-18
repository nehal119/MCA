#include <stdio.h>
 
int main() {
  int number, iterator;
  long int fatorial = 1;
  printf("Enter your number: ");
  scanf("%d", &number);
  for (iterator = 1; iterator <= number; iterator++) {
    fatorial = iterator * fatorial;
  }
  printf("Factorial is: %ld \n", fatorial);
}
