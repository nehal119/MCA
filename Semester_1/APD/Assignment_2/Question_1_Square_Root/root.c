#include <stdio.h>
#include <math.h>

void looperFunc () {
  int number;
  printf("Enter your number: ");
  scanf("%d", &number);
  printf("Square Root of the given number is: %f", sqrt(number));
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}