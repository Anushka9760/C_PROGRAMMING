#include <stdio.h>
#include <string.h>

union ExtraInfo
{
    int code;
    char category[20];
};

struct Item
{
    int id;
    char name[50];
    int quantity;
    float price;
    union ExtraInfo info;
};

struct Item inventory[100];

int n = 0;

void addItem()
{
    printf("\nEnter Item ID: ");
    scanf("%d", &inventory[n].id);

    printf("Enter Item Name: ");
    scanf(" %[^\n]", inventory[n].name);

    printf("Enter Quantity: ");
    scanf("%d", &inventory[n].quantity);

    printf("Enter Price: ");
    scanf("%f", &inventory[n].price);

    printf("Enter Category: ");
    scanf(" %[^\n]", inventory[n].info.category);

    n++;

    printf("\nItem added successfully!\n");
}

void updateQuantity()
{
    int id;
    int i;
    
    printf("\nEnter Item ID: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (inventory[i].id == id)
        {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("\nQuantity updated successfully!\n");
            return;
        }
    }

    printf("\nItem not found!\n");
}

void displayInventory()
{
    int i;

    if (n == 0)
    {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\n========== INVENTORY ==========\n");

    for (i = 0; i < n; i++)
    {
        printf("\nItem %d\n", i + 1);
        printf("ID       : %d\n", inventory[i].id);
        printf("Name     : %s\n", inventory[i].name);
        printf("Quantity : %d\n", inventory[i].quantity);
        printf("Price    : %.2f\n", inventory[i].price);
        printf("Category : %s\n", inventory[i].info.category);
    }
}

void deleteItem()
{
    int id;
    int i, j;

    printf("\nEnter Item ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (inventory[i].id == id)
        {
            for (j = i; j < n - 1; j++)
            {
                inventory[j] = inventory[j + 1];
            }

            n--;

            printf("\nItem deleted successfully!\n");
            return;
        }
    }

    printf("\nItem not found!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n==============================");
        printf("\n  INVENTORY MANAGEMENT SYSTEM");
        printf("\n==============================");
        printf("\n1. Add Item");
        printf("\n2. Update Quantity");
        printf("\n3. Display Inventory");
        printf("\n4. Delete Item");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addItem();
                break;

            case 2:
                updateQuantity();
                break;

            case 3:
                displayInventory();
                break;

            case 4:
                deleteItem();
                break;

            case 5:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}