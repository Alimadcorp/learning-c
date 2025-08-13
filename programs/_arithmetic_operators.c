#include <stdio.h>
#include <conio.h>

void main(){
	int a, b, sum;
	a = 10;
	b = 40;
	sum = a + b;
	printf("The result of a+b=%d.", sum);
	sum = a * b;
	printf("The result of a*b=%d.", sum);
	sum = b / a;
	printf("The result of b/a=%d.", sum);
	sum = b - a;
	printf("The result of b-a=%d.", sum);
	sum = a - b;
	printf("The result of a-b=%d.", sum);
	getch();
}