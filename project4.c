#include <stdio.h>
#include <string.h>

char names[100][50];
char phones[100][50];
char emails[100][50];
char addresses[100][100];
int count = 0;

void addContact() {
    printf("Enter Name: \n");
    scanf("%s", names[count]);

    printf("Enter Phone: \n");
    scanf("%s", phones[count]);

    printf("Enter Email: \n");
    scanf("%s", emails[count]);

    printf("Enter Address (one word): \n");
    scanf("%s", addresses[count]);
        count++;
        printf("Contact added successfully!\n");
    }

void viewContacts() {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | %s | %s | %s\n", i+1,
               names[i], phones[i], emails[i], addresses[i]);
    }
}

void searchContact() {
    char keyword[50];
    printf("Enter name or phone to search: \n");
    scanf("%s", keyword);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(names[i], keyword) || strstr(phones[i], keyword)) {
            printf("Found: %s\n | %s\n | %s\n | %s\n",
                   names[i], phones[i], emails[i], addresses[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No contact found.\n");
    }
}

void deleteContact() {
    char name[50];
    printf("Enter name to delete: \n");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], name) == 0) {
            for (int j = i; j < count - 1; j++) {
                strcpy(names[j], names[j+1]);
                strcpy(phones[j], phones[j+1]);
                strcpy(emails[j], emails[j+1]);
                strcpy(addresses[j], addresses[j+1]);
            }
            count--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Address Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter choice: \n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addContact();
             break;
            case 2: viewContacts();
             break;
            case 3: searchContact();
             break;
            case 4: deleteContact();
             break;
            case 5: printf("Exiting...\n");
             break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}