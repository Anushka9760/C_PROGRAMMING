#include <stdio.h>
int main()
{
    int num1, num2, input,add,substract,multiplication,division;
    printf("enter two numbers:");
    scanf("%d %d", &num1, &num2);
    printf(" 1.Add \n 2.Subtract\n 3.multiplication\n 4.division\n");
    scanf("%d", &input);
    scanf("%d", &add);
    scanf("%d", &substract);
    scanf("%d", &multiplication);
    scanf("%d", &division);
    switch (input)
    {
    case 1:
        add = num1 + num2;
        printf("addition:%d", add);
        break;
    case 2:
        substract = num1 - num2;
        printf("substraction:%d", substract);
        break;
    case 3:
        multiplication = num1 * num2;
        printf("multiplication:%d", multiplication);
        break;
    case 4:
        division = num1 / num2;
        printf("division:%d\n", division);
        break;
    default:
        printf("invalid");
    }
    return 0;
}