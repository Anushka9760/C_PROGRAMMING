#include <stdio.h>

int main()
{
    float test1, test2, finalScore;

    printf("Enter Test 1 score: ");
    scanf("%f", &test1);

    printf("Enter Test 2 score: ");
    scanf("%f", &test2);

    finalScore = (test1 + test2) / 2;

    printf("Final Score = %.2f\n", finalScore);

    return 0;
}