#include<stdio.h>

void looperFunc () {
  int firstNum, secondNum = 0;
  printf("Enter first number: ");
  scanf("%d", &firstNum);
  printf("Enter second number: ");
  scanf("%d", &secondNum);
  printf("Swapping variables...\n");
  firstNum = firstNum + secondNum;
  secondNum = firstNum - secondNum;
  firstNum = firstNum - secondNum;
  printf("First number is: %d \n", firstNum);
  printf("Second number is: %d \n", secondNum);
}
int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}