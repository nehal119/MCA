#include <stdio.h>
#include <math.h>

void sqRoot () {
  int number;
  printf("Enter your number: ");
  scanf("%d", &number);
  printf("Square Root of the given number is: %f", sqrt(number));
}

int main() {
  int toContinue;
  sqRoot();
  printf("\nDo you want to continue? (1 to continue / 0 to stop) ");
  scanf("%d", &toContinue);
  while (toContinue == 1) {
    sqRoot();
    printf("\nDo you want to continue? (1 to continue / 0 to stop) ");
    scanf("%d", &toContinue);
  }
}