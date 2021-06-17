#include <stdio.h>

// use Euclidean algorithm which is the main algorithm used for this purpose.
// The idea is, GCD of two numbers doesn’t change if smaller number is subtracted from a bigger number.

int gcdRec(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b) return gcdRec(a-b, b);
    return gcdRec(a, b-a);
}

int gcdLoop (int m, int n) {
  while(m != n) {
      if(m > n) 
        m -= n;
      else n -= m;
  }
  return m;
}

void looperFunc () {
  int m, n;
  printf("Enter two positive integers: ");
  scanf("%d %d",&m,&n);

  // printf("\nGCD using loop is: %d \n", gcdLoop(m, n));

  printf("\nGCD of %d and %d using recursion is: %d \n", m, n, gcdRec(m, n));
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}

// The time complexity for the above algorithm is O(log(max(a,b)))
// So the worst-case time complexity would be O(n) where a >= fib(n) and b >= fib(n+1).

// time complexity of the algorithm increases linearly as the terms grow exponentially 
// hence the time complexity would be log(max(a,b))