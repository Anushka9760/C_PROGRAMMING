#include <stdio.h>

int main() {
    char name[5][20];
    int roll[5];
    float marks[5];
    float sum = 0, avg;

    for (int i = 0; i < 5; i++) {
        printf("Enter Name: ");
        scanf("%s", name[i]);

        printf("Enter Roll Number: ");
        scanf("%d", &roll[i]);

        printf("Enter Marks: ");
        scanf("%f", &marks[i]);

        sum += marks[i];
    }

    avg = sum / 5;

    printf("Student Details:\n");
   
    for (int i = 0; i < 5; i++) {
        printf("roll no.: %d name: %s marks: %.2f\n", roll[i], name[i], marks[i]);
    }

    printf("Average Marks = %.2f", avg);

    return 0;
}