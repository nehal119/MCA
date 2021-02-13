#include <stdio.h>

void prime(int n) {
  int i, flag = 0;
  for (i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }
  if (flag == 0)
    printf("%d, ", n);
}

void looperFunc () {
  int x1, x2;
  printf("Enter start of search: ");
  scanf("%d", &x1);
  printf("Enter end of search: ");
  scanf("%d", &x2);
  if (x1 < x2) {
    for (int i = x1; i<x2; i++) {
      prime(i);
    }
  } else {
      for (int i = x2; i<x1; i++) {
      prime(i);
    }
  }
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}