#include <stdio.h>
#include <conio.h>

void main(){
	int a, b, sum;
	a = 10;
	b = 40;
	sum = a + b;
	printf("The result of a+b=%d.\n", sum);
	sum = a * b;
	printf("The result of a*b=%d.\n", sum);
	sum = b / a;
	printf("The result of b/a=%d.\n", sum);
	sum = b - a;
	printf("The result of b-a=%d.\n", sum);
	sum = a - b;
	printf("The result of a-b=%d.\n", sum);
	getch();
}