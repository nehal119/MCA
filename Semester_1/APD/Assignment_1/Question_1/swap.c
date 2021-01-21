#include<stdio.h>

void swapFunc () {
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
  int toContinue;
  swapFunc();
  printf("\nDo you want to continue? (1 to continue / 0 to stop) ");
  scanf("%d", &toContinue);
  while (toContinue == 1) {
    swapFunc();
    printf("\nDo you want to continue? (1 to continue / 0 to stop) ");
    scanf("%d", &toContinue);
  }
}