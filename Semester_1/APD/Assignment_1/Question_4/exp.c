#include<stdio.h>
 
void main() {
    int i, n;
    float x, sum, t;
     
    printf("Enter the value for x (in degree): ");
    scanf("%f",&x);
     
    printf("Enter the value for n (integer): ");
    scanf("%d",&n);

    // convert into radian
    x=x*3.14159/180;
    t=x;
    sum=x;
     
    /* Loop to calculate the value of Sin */
    for(i=1;i<=n;i++)
    {
        t=(t*(-1)*x*x)/(2*i*(2*i+1));
        sum=sum+t;
    }

    printf("The value of Sin(%f) = %.4f \n",x,sum);
}