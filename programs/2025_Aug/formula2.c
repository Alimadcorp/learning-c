#include <stdio.h>
#include <conio.h>

void main(){
    int L, H, A, B, x, x2;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    x2 = 2 * x;
    L = (x2 + 1) * (x * x * x - 1);
    H = x2 - 1;
    A = (x - 1) * (x2 + 1);
    B = (L * H) / A;
    printf("Value of second polynomial is %d", B);
    getch();
}