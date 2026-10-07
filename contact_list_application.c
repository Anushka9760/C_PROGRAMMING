#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[20];
    char email[60];
};

struct ContactList
{
    struct Contact *contacts;
    int size;
    int capacity;
};

void initializelist(struct ContactList *list)
{
    (*list).size = 0;
    (*list).capacity = 2;
    (*list).contacts = malloc((*list).capacity * sizeof(struct Contact));
    if ((*list).contacts == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}
void resizelist(struct ContactList *list)
{
    (*list).capacity = (*list).capacity * 2;
    (*list).contacts = realloc((*list).contacts, (*list).capacity * sizeof(struct Contact));
    if ((*list).contacts == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("\n List resized . New capacity=%d\n", (*list).capacity);
}

void addcontact(struct ContactList *list)
{
    if ((*list).size == (*list).capacity)
    {
        resizelist(list);
    }
    printf("\nEnter name:");
    scanf("%49s", (*list).contacts[(*list).size].name);
    printf("Enter phone number:");
    scanf("%19s", (*list).contacts[(*list).size].phone);
    printf("Enter email:");
    scanf("%59s", (*list).contacts[(*list).size].email);
    (*list).size++;
    printf("\n Contacts added sucessfully!.\n");
}
void displaycontacts(struct ContactList *list)
{
    if ((*list).size == 0)
    {
        printf("\n No contacts available.\n");
        return;
    }
    printf("\n========CONTACT LIST========\n");
    for (int i = 0; i < (*list).size; i++)
    {
        printf("\n Contact %d\n", i + 1);
        printf("Name: %s\n", (*list).contacts[i].name);
        printf("Phone: %s\n", (*list).contacts[i].phone);
        printf("Email: %s\n", (*list).contacts[i].email);
    }
}
void searchcontact(struct ContactList *list)
{
    char name[50];
    int found = 0;
    printf("\n Enter name to search:");
    scanf("%49s", name);
    for (int i = 0; i < (*list).size; i++)
    {
        if (strcmp((*list).contacts[i].name, name) == 0)
        {
            printf("\n Contact found!\n");
            printf("Name: %s\n", (*list).contacts[i].name);
            printf("Phone: %s\n", (*list).contacts[i].phone);
            printf("Email: %s\n", (*list).contacts[i].email);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("\n Contact not found!\n");
    }
}
void deletecontact(struct ContactList *list)
{
    char name[50];
    int found = -1;
    printf("\nEnter name to delete:");
    scanf("%49s", name);
    for (int i = 0; i < (*list).size; i++)
    {
        if (strcmp((*list).contacts[i].name, name) == 0)
        {
            found = 1;
            break;
        }
    }
    if (found == -1)
    {
        printf("\nContact not found.\n");
        return;
    }
    for (int i = found; i < (*list).size - 1; i++)
    {
        (*list).contacts[i] = (*list).contacts[i + 1];
    }
    (*list).size--;
    printf("\nContact deleted successfully!\n");
}
void freelist(struct ContactList *list)
{
    free((*list).contacts);
    (*list).contacts = NULL;
}
int main()
{
    struct ContactList list;
    int choice;
    initializelist(&list);
    while (1)
    {
        printf("\n========CONTACT LIST========\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contacts\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("===========================================\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addcontact(&list);
            break;
        case 2:
            deletecontact(&list);
            break;
        case 3:
            searchcontact(&list);
            break;
        case 4:
            searchcontact(&list);
            break;
        case 5:
            freelist(&list);
            printf("\n Memory freed. Program ended.\n");
            return 0;

        default:
            printf("\n Invalid choice!\n");
            break;
        }
    }
    return 0;
}