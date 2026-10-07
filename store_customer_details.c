#include <stdio.h>
int main()
{
    char name[100];
    char phone[15];
    char order[200];
    float totalcost;
    printf("===== CUSTOMER DETAILS =====\n");

    printf("Enter customer full name: ");
    scanf(" %[^\n]", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    printf("Enter order details: ");
    scanf(" %[^\n]", order);

    printf("Enter total cost: ");
    scanf("%f", &totalcost);

    printf("\n===== STORED CUSTOMER DETAILS =====\n");

    printf("Customer Name : %s\n", name);
    printf("Phone Number  : %s\n", phone);
    printf("Order Details : %s\n", order);
    printf("Total Cost    : %.2f\n", totalcost);
    return 0;
}