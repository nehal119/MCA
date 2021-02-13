#include <stdio.h>
#include <stdlib.h>

float absolute(float num) {
  if(num < 0){
    num = -num;
  }
  return num;
}

// x_i = (number / x_i + x_i) / 2

void looperFunc () {
  float number;
  float r;
  printf("Enter your number: ");
  scanf("%f", &number);
  printf("Entered number is: %f\n", number);
  r = number;
  while (absolute((r * r) - number) >= 0.00001) {
    r = (number / r + r) / 2.0;
  }
  printf("Square Root of the given number is: %g", r);
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}