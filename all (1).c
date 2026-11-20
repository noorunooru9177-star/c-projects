
#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float cutoff;
    char city[30];
    char dream[50];
};

void getDetails(struct Student s[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Cut-off Mark: ");
        scanf("%f", &s[i].cutoff);

        printf("Enter City: ");
        scanf(" %[^\n]", s[i].city);

        printf("Enter Dream: ");
        scanf(" %[^\n]", s[i].dream);
    }
}

void displayDetails(struct Student s[], int n)
{
    int i;

    printf("\n====================================");
    printf("\n       STUDENT RECORD DETAILS");
    printf("\n====================================");

    for(i = 0; i < n; i++)
    {
        printf("\n\nStudent %d", i + 1);

        printf("\nRoll Number : %d", s[i].roll);
        printf("\nName        : %s", s[i].name);
        printf("\nCut-off     : %.2f", s[i].cutoff);
        printf("\nCity        : %s", s[i].city);
        printf("\nDream       : %s", s[i].dream);

        printf("\n------------------------------------");
    }
}

int main()
{
    struct Student s[100];
    int n;

    printf("====================================");
    printf("\n  STUDENT RECORD MANAGEMENT SYSTEM");
    printf("\n====================================");

    printf("\nEnter Number of Students: ");
    scanf("%d", &n);

    if(n <= 0 || n > 100)
    {
        printf("\nInvalid Student Count!");
        return 0;
    }

    getDetails(s, n);

    displayDetails(s, n);

    printf("\n\nThank You!");

    return 0;
}

