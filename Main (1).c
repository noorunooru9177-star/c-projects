
#include <stdio.h>

int main()
{
    int roll, m1, m2, m3, m4, m5;
    int total;
    float average;
    char name[50], grade;

    printf("STUDENT MARKS MANAGEMENT SYSTEM\n");
    printf("--------------------------------\n");

    printf("Enter Student Details\n");

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Subject 1 Mark: ");
    scanf("%d", &m1);

    printf("Enter Subject 2 Mark: ");
    scanf("%d", &m2);

    printf("Enter Subject 3 Mark: ");
    scanf("%d", &m3);

    printf("Enter Subject 4 Mark: ");
    scanf("%d", &m4);

    printf("Enter Subject 5 Mark: ");
    scanf("%d", &m5);

    total = m1 + m2 + m3 + m4 + m5;

    average = total / 5.0;

    if(average >= 90)
        grade = 'A';
    else if(average >= 80)
        grade = 'B';
    else if(average >= 70)
        grade = 'C';
    else if(average >= 60)
        grade = 'D';
    else
        grade = 'F';

    printf("\nSTUDENT RESULT\n");
    printf("--------------------\n");

    printf("Roll Number : %d\n", roll);
    printf("Name        : %s\n", name);
    printf("Total       : %d\n", total);
    printf("Average     : %.2f\n", average);
    printf("Grade       : %c\n", grade);

    if(average >= 40)
        printf("Result      : PASS\n");
    else
        printf("Result      : FAIL\n");

    return 0;
}
