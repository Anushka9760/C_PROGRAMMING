#include <stdio.h>
#include <string.h>

struct Book
{
    char title[50];
    char author[50];
    char isbn[20];
    int available;
    char borrowedBy[50];
};

struct Book books[100];
int count = 0;

void addBook()
{
    printf("\nEnter Book Title: ");
    scanf(" %[^\n]", books[count].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[count].author);

    printf("Enter ISBN: ");
    scanf(" %[^\n]", books[count].isbn);

    books[count].available = 1;
    strcpy(books[count].borrowedBy, "None");

    count++;

    printf("\nBook added successfully!\n");
}

void searchBook()
{
    char isbn[20];
    int found = 0;

    printf("\nEnter ISBN to search: ");
    scanf(" %[^\n]", isbn);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].isbn, isbn) == 0)
        {
            printf("\nBook Found!\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("ISBN: %s\n", books[i].isbn);

            if (books[i].available == 1)
                printf("Status: Available\n");
            else
                printf("Status: Borrowed\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nBook not found!\n");
}

void borrowBook()
{
    char isbn[20];
    char name[50];

    printf("\nEnter ISBN: ");
    scanf(" %[^\n]", isbn);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].isbn, isbn) == 0)
        {
            if (books[i].available == 0)
            {
                printf("\nBook is already borrowed!\n");
                return;
            }

            printf("Enter Borrower's Name: ");
            scanf(" %[^\n]", name);

            books[i].available = 0;
            strcpy(books[i].borrowedBy, name);

            printf("\nBook borrowed successfully!\n");
            return;
        }
    }

    printf("\nBook not found!\n");
}

void returnBook()
{
    char isbn[20];

    printf("\nEnter ISBN: ");
    scanf(" %[^\n]", isbn);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].isbn, isbn) == 0)
        {
            if (books[i].available == 1)
            {
                printf("\nBook is already available!\n");
                return;
            }

            books[i].available = 1;
            strcpy(books[i].borrowedBy, "None");

            printf("\nBook returned successfully!\n");
            return;
        }
    }

    printf("\nBook not found!\n");
}

void displayBooks()
{
    if (count == 0)
    {
        printf("\nNo books in library!\n");
        return;
    }

    printf("\n===== LIBRARY BOOKS =====\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nBook %d\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("ISBN: %s\n", books[i].isbn);

        if (books[i].available == 1)
            printf("Status: Available\n");
        else
        {
            printf("Status: Borrowed\n");
            printf("Borrowed By: %s\n", books[i].borrowedBy);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n==============================\n");
        printf("   LIBRARY MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Display Books\n");
        printf("6. Exit\n");
        printf("==============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            searchBook();
            break;

        case 3:
            borrowBook();
            break;

        case 4:
            returnBook();
            break;

        case 5:
            displayBooks();
            break;

        case 6:
            printf("\nThank you!\n");
            break;

        default:
            printf("\nInvalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}