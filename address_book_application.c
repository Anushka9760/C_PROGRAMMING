#include <stdio.h>
#include <string.h>

char name[100][50];
char phone[100][20];
char email[100][50];
char address[100][100];

int count = 0;

void addContact()
{
    if (count >= 100)
    {
        printf("Address book is full!\n");
        return;
    }

    printf("\nEnter Name: ");
    scanf(" %[^\n]", name[count]);

    printf("Enter Phone: ");
    scanf(" %[^\n]", phone[count]);

    printf("Enter Email: ");
    scanf(" %[^\n]", email[count]);

    printf("Enter Address: ");
    scanf(" %[^\n]", address[count]);

    count++;

    printf("\nContact added successfully!\n");
}

void viewContacts()
{
    if (count == 0)
    {
        printf("\nNo contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nContact %d\n", i + 1);
        printf("Name    : %s\n", name[i]);
        printf("Phone   : %s\n", phone[i]);
        printf("Email   : %s\n", email[i]);
        printf("Address : %s\n", address[i]);
    }
}

void searchContact()
{
    char identity[50];
    int found = 0;

    printf("\nEnter name to search: ");
    scanf(" %[^\n]", identity);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(name[i], identity) == 0)
        {
            printf("\nContact Found!\n");
            printf("Name    : %s\n", name[i]);
            printf("Phone   : %s\n", phone[i]);
            printf("Email   : %s\n", email[i]);
            printf("Address : %s\n", address[i]);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nContact not found.\n");
    }
}

void deleteContact()
{
    char delName[50];
    int found = 0;

    printf("\nEnter name to delete: ");
    scanf(" %[^\n]", delName);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(name[i], delName) == 0)
        {
            for (int j = i; j < count - 1; j++)
            {
                strcpy(name[j], name[j + 1]);
                strcpy(phone[j], phone[j + 1]);
                strcpy(email[j], email[j + 1]);
                strcpy(address[j], address[j + 1]);
            }

            count--;
            found = 1;

            printf("\nContact deleted successfully!\n");
            break;
        }
    }

    if (found == 0)
    {
        printf("\nContact not found.\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n============================\n");
        printf("      ADDRESS BOOK\n");
        printf("============================\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("============================\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact();
            break;

        case 2:
            viewContacts();
            break;

        case 3:
            searchContact();
            break;

        case 4:
            deleteContact();
            break;

        case 5:
            printf("\nExiting Address Book...\n");
            break;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}