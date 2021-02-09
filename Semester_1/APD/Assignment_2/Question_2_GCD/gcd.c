#include <stdio.h>
#include <time.h>

int gcdRec(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b) return gcdRec(a-b, b);
    return gcdRec(a, b-a);
}

int gcdLoop (int n1, int n2) {
  while(n1!=n2) {
      if(n1 > n2) 
        n1 -= n2;
      else n2 -= n1;
  }
  return n1;
}

void printTimeTaken (clock_t t) {
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Took %f seconds to complete \n", time_taken);
}

void looperFunc () {
  int n1, n2;
  clock_t t;
  printf("Enter two positive integers: ");
  scanf("%d %d",&n1,&n2);

  t = clock();
  printf("\nGCD using loop is: %d \n", gcdLoop(n1, n2));
  printTimeTaken(clock() - t);

  t = clock();
  printf("\nGCD using recursion is: %d \n", gcdRec(n1, n2));
  printTimeTaken(clock() - t);
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}