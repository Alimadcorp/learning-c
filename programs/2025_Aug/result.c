#include <stdio.h>
#include <conio.h>

void main(){
    char subjects[5][20] = {"Maths", "Science", "English", "History", "Geography"};
    int marks[5] = { 98, 31, 59, 98, 32 };
    int total = 0, max = 100;
    char name[] = "Arham", f_name[] = "Abdullah";
    int roll = 101, class = 11;

    printf("Student Name: %s\n", name);
    printf("Father's Name: %s\n", f_name);
    printf("Roll No: %d\n", roll);
    printf("Class: %d\n\n", class);

    printf("Sr.\tSubject\t\tTotal\t\tObtained\n");
    for(int i = 0; i < 5; i++) {
        printf("%d\t%-10s\t%d\t\t%d\n", i + 1, subjects[i], max, marks[i]);
        total += marks[i];
    }

    printf("\nTotal Marks: %d/%d\n", total, max * 5);
    printf("Percentage: %.2f%%\n", (total * 100.0) / (max * 5));
    getch();
}