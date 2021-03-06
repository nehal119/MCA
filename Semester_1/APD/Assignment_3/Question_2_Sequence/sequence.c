#include <stdio.h>

// xn+1= (a * xn+ b) mod m for n >= 0
// 3,3,7,7,7 ==> 3 1 2 0 1 2 0

void looperFunc () {
  int x0;
  int m, a, b, n;
  printf("x0, m, a, b, n in respective order: \n");
  scanf("%d", &x0);
  scanf("%d", &m);
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &n);
  for (int i = 0; i<n; i++) {
    printf("%d ", x0);
    x0 = (((x0 * a) + b) % m);
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