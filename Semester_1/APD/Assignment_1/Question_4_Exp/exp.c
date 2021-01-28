#include <stdio.h>
#include <math.h>

int fac(int x) {
	int i, fac = 1;
	for(i = 1;i <= x; i++)
		fac = fac * i;
	return fac;
}

void looperFunc () {
 	float x, angle, sum = 0;
	int i, j, limit;

	printf("Enter the value of x for sinx series: ");
	scanf("%f", &x);

	printf("Enter the limit n to expand the series: ");
	scanf("%d", &limit);

	angle = x;
	x = x * (3.1415 / 180);

	for(i = 1, j = 1; i <= limit; i++, j = j+2) {
		if(i%2 != 0) {
			sum = sum + pow(x,j) / fac(j);
		}
		else {
			sum = sum - pow(x,j) / fac(j);
		}
	}
	printf("Sin(%0.1f): %f", angle, sum);
}

int main() {
  int toContinue = 1;
  while (toContinue == 1) {
    looperFunc();
    printf("\n\nDo you want to continue? (1 to continue || 0 to exit)");
    scanf("%d", &toContinue);
  }
}