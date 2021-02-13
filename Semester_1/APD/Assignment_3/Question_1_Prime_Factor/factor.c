#include <stdio.h>
#include <math.h>

void looperFunc () {
  int number;
  printf("Enter your number: ");
  scanf("%d", &number);
  printf("Prime factors are: ");
  // List are multiples of 2
  while (number%2 == 0) { 
    printf("%d ", 2); 
    number = number/2; 
  }
  // Check for other factors other than 2
  for (int i = 3; i <= sqrt(number); i = i+2) { 
    while (number%i == 0) { 
      printf("%d ", i); 
      number = number/i; 
    }
  }
  // Handle last factor
  if (number > 2) 
    printf ("%d ", number); 
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}