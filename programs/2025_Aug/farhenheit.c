#include <stdio.h>
#include <conio.h>

void main(){
    float C, F;
    printf("Temperature in celcius: ");
    scanf("%f", &C);
    F = (C * 9 / 5) + 32;
    printf("Temperature in farhenheit: %.4f\n", F);
    getch();
}
