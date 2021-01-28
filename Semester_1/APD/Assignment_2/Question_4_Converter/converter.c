#include<stdio.h>
#include<stdlib.h>

void convert_to_x_base(int num, int base) {    
    int rem;
    // base condition
    if (num == 0){
        return;
    }
    else {
        rem = num % base; // get the rightmost digit        
        convert_to_x_base(num/base, base);  // recursive call        
        if(base == 16 && rem >= 10) {
            printf("%c", rem+55);
        }
        else {
            printf("%d", rem);
        }
    }

}

void looperFunc() {
    int num, choice, base;
    printf("Select conversion type: \n\n");
    printf("1. Decimal to binary. \n");
    printf("2. Decimal to octal. \n");
    printf("3. Decimal to hexadecimal. \n");              
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            base = 2;
            break;
        case 2:
            base = 8;
            break;              
        case 3:
            base = 16;
            break;
        default:
            printf("Choice not available.\n\n");
            return;
    }
    printf("Enter your number: ");
    scanf("%d", &num);
    printf("Equivalent of %d in base %d is: ", num, base);
    convert_to_x_base(num, base);
    printf("\n\n");
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}