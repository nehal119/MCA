#include <stdio.h>

void reverseFunc () {
  int number, checkPalindrome, reverse = 0;
  printf("Enter an integer: ");
  scanf("%d", &number);
  checkPalindrome = number;
  while (number != 0) {
    reverse = reverse * 10;
    reverse = reverse + number % 10;
    number = number / 10;
  }
  printf("Reverse of the given interger is: %d \n", reverse);
  if (checkPalindrome == reverse) {
    printf("The given number is a palindrome.\n");
  } else {
    printf("The given number is not palindrome.\n");
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