#include<stdio.h>
#include<stdlib.h>

void conversion(int num, int base) {
    int remainder = num % base;
    if(num == 0) return;
    conversion(num / base, base);
    if(remainder < 10) {
          printf("%d", remainder);
    }
    else {
          printf("%c", remainder - 10 + 'A' );
    }
}

void looperFunc() {
    int num, choice;
    printf("Enter your number: ");
    scanf("%d", &num);
    printf("\nEquivalent of %d in base %d is: ", num, 2);
    conversion(num, 2);
    printf("\nEquivalent of %d in base %d is: ", num, 8);
    conversion(num, 8);
    printf("\nEquivalent of %d in base %d is: ", num, 16);
    conversion(num, 16);
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}