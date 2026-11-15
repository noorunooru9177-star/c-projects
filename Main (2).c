
#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char name[100];
    char author[100];
    int issued;
};

struct Book books[100];
int count = 0;

void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", books[count].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[count].author);

    books[count].issued = 0;
    count++;

    printf("\nBook Added Successfully!\n");
}

void displayBooks() {
    int i;

    if (count == 0) {
        printf("\nNo Books Available!\n");
        return;
    }

    printf("\nID\tName\tAuthor\tStatus\n");

    for (i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%s\n",
        books[i].id,
        books[i].name,
        books[i].author,
        books[i].issued ? "Issued" : "Available");
    }
}

void searchByID() {
    int id, i;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", books[i].id);
            printf("Name: %s\n", books[i].name);
            printf("Author: %s\n", books[i].author);
            printf("Status: %s\n",
            books[i].issued ? "Issued" : "Available");
            return;
        }
    }

    printf("\nBook Not Found!\n");
}

void searchByName() {
    char name[100];
    int i;

    printf("\nEnter Book Name: ");
    scanf(" %[^\n]", name);

    for (i = 0; i < count; i++) {
        if (strcmp(books[i].name, name) == 0) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", books[i].id);
            printf("Name: %s\n", books[i].name);
            printf("Author: %s\n", books[i].author);
            printf("Status: %s\n",
            books[i].issued ? "Issued" : "Available");
            return;
        }
    }

    printf("\nBook Not Found!\n");
}

void issueBook() {
    int id, i;

    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued == 0) {
                books[i].issued = 1;
                printf("\nBook Issued Successfully!\n");
            } else {
                printf("\nBook Already Issued!\n");
            }
            return;
        }
    }

    printf("\nBook Not Found!\n");
}

void returnBook() {
    int id, i;

    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued == 1) {
                books[i].issued = 0;
                printf("\nBook Returned Successfully!\n");
            } else {
                printf("\nBook Was Not Issued!\n");
            }
            return;
        }
    }

    printf("\nBook Not Found!\n");
}

void updateBook() {
    int id, i;

    printf("\nEnter Book ID to Update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("Enter New Book Name: ");
            scanf(" %[^\n]", books[i].name);

            printf("Enter New Author Name: ");
            scanf(" %[^\n]", books[i].author);

            printf("\nBook Updated Successfully!\n");
            return;
        }
    }

    printf("\nBook Not Found!\n");
}

void totalBooks() {
    printf("\nTotal Books: %d\n", count);
}

void availableBooks() {
    int i, found = 0;

    printf("\nAvailable Books:\n");

    for (i = 0; i < count; i++) {
        if (books[i].issued == 0) {
            printf("\nID: %d", books[i].id);
            printf("\nName: %s", books[i].name);
            printf("\nAuthor: %s\n", books[i].author);
            found = 1;
        }
    }

    if (found == 0) {
        printf("\nNo Available Books!\n");
    }
}

int main() {
    int choice;

    printf("\n========== LIBRARY MANAGEMENT SYSTEM ==========\n");
    printf("1. Add New Book\n");
    printf("2. Display All Books\n");
    printf("3. Search Book by ID\n");
    printf("4. Search Book by Name\n");
    printf("5. Issue Book\n");
    printf("6. Return Book\n");
    printf("7. Update Book Details\n");
    printf("8. Count Total Books\n");
    printf("9. Display Available Books\n");
    printf("10. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: addBook(); break;
        case 2: displayBooks(); break;
        case 3: searchByID(); break;
        case 4: searchByName(); break;
        case 5: issueBook(); break;
        case 6: returnBook(); break;
        case 7: updateBook(); break;
        case 8: totalBooks(); break;
        case 9: availableBooks(); break;
        case 10:
            printf("\nThank You! Exiting Program...\n");
            break;
        default:
            printf("\nInvalid Choice!\n");
    }

    return 0;
}
