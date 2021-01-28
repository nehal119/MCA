#include <stdio.h>
 
long int factCalcRec(int number) {
  if (number < 1) {
    return 1;
  }
  return number*factCalcRec(number - 1);
}

long int factCalcItr(int number) {
  int iterator;
  long int fatorial = 1;
  for (iterator = 1; iterator <= number; iterator++) {
    fatorial = iterator * fatorial;
  }
  return fatorial;
}

void looperFunc () {
  int number;
  printf("Enter your number: ");
  scanf("%d", &number);
  printf("Factorial using loop is: %ld \n", factCalcItr(number));
  printf("Factorial using recursion is: %ld \n", factCalcRec(number));
}

int main() {
  int toContinue;
  looperFunc();
  printf("\nDo you want to continue? (1 to continue / 0 to stop) ");
  scanf("%d", &toContinue);
  while (toContinue == 1) {
    looperFunc();
    printf("\nDo you want to continue? (1 to continue / 0 to stop) ");
    scanf("%d", &toContinue);
  }
}
