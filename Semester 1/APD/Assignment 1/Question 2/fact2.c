#include <stdio.h>
 
long int factCalc(int number) {
  if (number >= 1) {
    return number*factCalc(number - 1);
  } else {
    return 1;
  }
}

int main() {
  int number;
  printf("Enter your number: ");
  scanf("%d", &number);
  printf("Factorial is: %ld \n", factCalc(number));
}
