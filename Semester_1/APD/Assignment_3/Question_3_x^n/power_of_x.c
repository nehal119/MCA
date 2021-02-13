#include <stdio.h>
#include <math.h>

int power(int x, int n) {
  int pi = 1;
  for (int i = 0; i<n; i++) {
    pi = pi * x;
  }
  return pi;
}

void looperFunc () {
  int x, n;
  printf("Enter your number: ");
  scanf("%d", &x);
  printf("Enter your power: ");
  scanf("%d", &n);
  printf("Solution is: %d", power(x, n));
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}