#include <stdio.h>
#include <string.h>

char names[100][50];
char phones[100][50];
char emails[100][50];
int count = 0;

void addContact()
{
    if (count < 100)
    {
        printf("Enter name: ");
        scanf("%49s", names[count]);

        printf("Enter phone: ");
        scanf("%49s", phones[count]);

        printf("Enter email: ");
        scanf("%49s", emails[count]);

        count++;
        printf("Contact added successfully!\n");
    }
    else
    {
        printf("Address book is full!\n");
    }
}

void displayContacts()
{
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s | %s | %s\n", i + 1, names[i], phones[i], emails[i]);
    }
}

void searchContact()
{
    char search[50];
    printf("Enter name to search: ");
    scanf("%49s", search);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(names[i], search) == 0)
        {
            printf("Found: %s | %s | %s\n", names[i], phones[i], emails[i]);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Contact not found!\n");
    }
}

void updateContact()
{
    char search[50];
    printf("Enter name to update: ");
    scanf("%49s", search);

    int found = -1;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(names[i], search) == 0)
        {
            found = i;
            break;
        }
    }

    if (found != -1)
    {
        printf("Enter new name: ");
        scanf("%49s", names[found]);

        printf("Enter new phone: ");
        scanf("%49s", phones[found]);

        printf("Enter new email: ");
        scanf("%49s", emails[found]);

        printf("Contact updated successfully!\n");
    }
    else
    {
        printf("Contact not found!\n");
    }
}

void deleteContact()
{
    char search[50];
    printf("Enter name to delete: ");
    scanf("%49s", search);

    int found = -1;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(names[i], search) == 0)
        {
            found = i;
            break;
        }
    }

    if (found != -1)
    {
        for (int j = found; j < count - 1; j++)
        {
            strcpy(names[j], names[j + 1]);
            strcpy(phones[j], phones[j + 1]);
            strcpy(emails[j], emails[j + 1]);
        }
        count--;
        printf("Contact deleted successfully!\n");
    }
    else
    {
        printf("Contact not found!\n");
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n--- Address Book ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            displayContacts();
            break;
        case 3:
            searchContact();
            break;
        case 4:
            updateContact();
            break;
        case 5:
            deleteContact();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
