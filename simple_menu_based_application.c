#include <stdio.h>

int main()
{
    int choice;
    int a, b;

    printf("===== MENU =====\n");
    printf("1. Add two numbers\n");
    printf("2. Subtract two numbers\n");
    printf("3. Multiply two numbers\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("Sum = %d\n", a + b);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("Difference = %d\n", a - b);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("Product = %d\n", a * b);
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}