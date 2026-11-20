#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rollNo;
    char name[50];
    char department[30];
    int year;
    float marks;
    char grade;
} Student;

Student *students = NULL;
int count = 0;
int capacity = 0;

void trackOperations() {
    static int operationCount = 0;
    operationCount++;
    printf("\n[System Log: Total operations in this session = %d]\n", operationCount);
}

char calculateGrade(float marks) {
    if (marks >= 90) return 'O';
    else if (marks >= 80) return 'A';
    else if (marks >= 70) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 50) return 'D';
    else return 'F';
}

void initSystem() {
    capacity = 2;
    students = (Student *)malloc(capacity * sizeof(Student));
    if (students == NULL) {
        printf("Critical Error: Initial memory allocation failed!\n");
        exit(1);
    }
}

void loadFromBinaryFile() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        return;
    }

    Student temp;
    while (fread(&temp, sizeof(Student), 1, fp) == 1) {
        if (count == capacity) {
            capacity *= 2;
            Student *tempPtr = (Student *)realloc(students, capacity * sizeof(Student));
            if (tempPtr == NULL) {
                printf("Error: Memory reallocation failed!\n");
                fclose(fp);
                return;
            }
            students = tempPtr;
        }
        students[count++] = temp;
    }
    fclose(fp);
}

void saveToFiles() {
    FILE *binFp = fopen("students_temp.dat", "wb");
    if (binFp == NULL) {
        printf("Error: Could not open binary file!\n");
        return;
    }
    if (count > 0) {
        fwrite(students, sizeof(Student), count, binFp);
    }
    fclose(binFp);

    remove("students.dat");
    rename("students_temp.dat", "students.dat");

    FILE *txtFp = fopen("students.txt", "w");
    if (txtFp == NULL) {
        printf("Error: Could not open text file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(txtFp, "%d | %s | %s | %d | %.2f | %c\n",
                students[i].rollNo, students[i].name, students[i].department,
                students[i].year, students[i].marks, students[i].grade);
    }
    fclose(txtFp);
}

void addStudent() {
    trackOperations();

    if (count == capacity) {
        capacity = (capacity == 0) ? 2 : capacity * 2;
        Student *tempPtr = (Student *)realloc(students, capacity * sizeof(Student));
        if (tempPtr == NULL) {
            printf("Error: Memory allocation failed!\n");
            return;
        }
        students = tempPtr;
    }

    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNo);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == s.rollNo) {
            printf("Error: Roll Number %d already exists!\n", s.rollNo);
            return;
        }
    }

    while (getchar() != '\n');
    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(s.department, sizeof(s.department), stdin);
    s.department[strcspn(s.department, "\n")] = '\0';

    printf("Enter Year of Study: ");
    scanf("%d", &s.year);

    printf("Enter Marks (0-100): ");
    scanf("%f", &s.marks);

    s.grade = calculateGrade(s.marks);

    students[count++] = s;
    saveToFiles();
    printf("Success: Student record added!\n");
}

void displayAll() {
    trackOperations();
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------\n");
    printf("%-10s %-20s %-15s %-6s %-8s %-6s\n", "Roll No", "Name", "Department", "Year", "Marks", "Grade");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-15s %-6d %-8.2f %-6c\n",
               students[i].rollNo, students[i].name, students[i].department,
               students[i].year, students[i].marks, students[i].grade);
    }
    printf("--------------------------------------------------------------------------\n");
}

void searchStudent() {
    trackOperations();
    if (count == 0) {
        printf("\nNo records available.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number : %d\n", students[i].rollNo);
            printf("Name        : %s\n", students[i].name);
            printf("Department  : %s\n", students[i].department);
            printf("Year        : %d\n", students[i].year);
            printf("Marks       : %.2f\n", students[i].marks);
            printf("Grade       : %c\n", students[i].grade);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

void updateStudent() {
    trackOperations();
    int roll;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            while (getchar() != '\n');
            printf("Enter New Name (current: %s): ", students[i].name);
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter New Department (current: %s): ", students[i].department);
            fgets(students[i].department, sizeof(students[i].department), stdin);
            students[i].department[strcspn(students[i].department, "\n")] = '\0';

            printf("Enter New Year (current: %d): ", students[i].year);
            scanf("%d", &students[i].year);

            printf("Enter New Marks (current: %.2f): ", students[i].marks);
            scanf("%f", &students[i].marks);

            students[i].grade = calculateGrade(students[i].marks);
            saveToFiles();
            printf("Success: Student record updated!\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

void deleteStudent() {
    trackOperations();
    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    int foundIndex = -1;
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Student with Roll Number %d not found.\n", roll);
        return;
    }

    for (int i = foundIndex; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;
    saveToFiles();
    printf("Success: Student record deleted!\n");
}

void countStudents() {
    trackOperations();
    printf("\nTotal Stored Student Records: %d\n", count);
}

void filterByMarks() {
    trackOperations();
    float minMarks;
    printf("\nEnter minimum marks threshold: ");
    scanf("%f", &minMarks);

    FILE *txtFp = fopen("students.txt", "r");
    if (txtFp == NULL) {
        printf("Error: Text file not found or no records exist.\n");
        return;
    }

    Student *filteredList = (Student *)calloc(count > 0 ? count : 1, sizeof(Student));
    if (filteredList == NULL) {
        printf("Error: Memory allocation with calloc() failed!\n");
        fclose(txtFp);
        return;
    }

    int matchCount = 0;
    Student temp;
    while (fscanf(txtFp, "%d | %49[^|] | %29[^|] | %d | %f | %c\n",
                  &temp.rollNo, temp.name, temp.department,
                  &temp.year, &temp.marks, &temp.grade) == 6) {
        if (temp.marks > minMarks) {
            filteredList[matchCount++] = temp;
        }
    }
    fclose(txtFp);

    if (matchCount == 0) {
        printf("No students found with marks greater than %.2f.\n", minMarks);
    } else {
        printf("\n--- Students with Marks > %.2f ---\n", minMarks);
        for (int i = 0; i < matchCount; i++) {
            printf("Roll: %d | Name: %s | Dept: %s | Marks: %.2f | Grade: %c\n",
                   filteredList[i].rollNo, filteredList[i].name,
                   filteredList[i].department, filteredList[i].marks, filteredList[i].grade);
        }
    }

    free(filteredList);
}

int main() {
    int choice;
    initSystem();
    loadFromBinaryFile();

    while (1) {
        printf("\n=== Student Record & File Management System ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search by Roll Number\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Count Total Students\n");
        printf("7. Filter by Marks\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: countStudents(); break;
            case 7: filterByMarks(); break;
            case 8:
                free(students);
                students = NULL;
                printf("Memory freed. Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please select between 1 and 8.\n");
        }
    }
    return 0;
}
