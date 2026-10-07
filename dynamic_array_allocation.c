#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("enter the no. of elements:");
    scanf("%d",&n);
    int *arr=malloc(n *sizeof(int));
    if (n<=0)
    {
        printf("invalid array size!");
        return 1;
    
    }
    printf("enter elements:");
    for (int i = 0; i < n; i++)
    {
       printf(" %d",i);
    }
    free(arr);
    arr=NULL;
    return 0;

    
}