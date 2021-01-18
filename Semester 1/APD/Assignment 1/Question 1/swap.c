#include<stdio.h>

int main() {
  int firstNum, secondNum = 0;
  printf("Enter first number: \n");
  scanf("%d", &firstNum);
  printf("Enter second number: \n");
  scanf("%d", &secondNum);
  printf("Swapping variables...\n");
  firstNum = firstNum + secondNum;
  secondNum = firstNum - secondNum;
  firstNum = firstNum - secondNum;
  printf("First number is: %d \n", firstNum);
  printf("Second number is: %d \n", secondNum);
}