#include <stdio.h>

struct Sale
{
    int id;
    char product[50];
    float amount;
};

void addSale()
{
    FILE *fp;
    struct Sale s;

    fp = fopen("sales.dat", "ab");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    printf("\nEnter Sale ID: ");
    scanf("%d", &s.id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", s.product);

    printf("Enter Sale Amount: ");
    scanf("%f", &s.amount);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("\nSales data saved successfully!\n");
}

void displaySales()
{
    FILE *fp;
    struct Sale s;

    fp = fopen("sales.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo sales data found.\n");
        return;
    }

    printf("\n========== SALES DATA ==========\n");

    printf("\nID\tProduct\t\tAmount\n");
    printf("--------------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("%d\t%-15s %.2f\n", s.id, s.product, s.amount);
    }

    fclose(fp);
}

void analyseSales()
{
    FILE *fp;
    struct Sale s;

    float total = 0;
    float average;
    float highest = 0;
    float lowest = 0;
    int count = 0;

    fp = fopen("sales.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo sales data found.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        total = total + s.amount;

        if (count == 0)
        {
            highest = s.amount;
            lowest = s.amount;
        }
        else
        {
            if (s.amount > highest)
            {
                highest = s.amount;
            }

            if (s.amount < lowest)
            {
                lowest = s.amount;
            }
        }

        count++;
    }

    fclose(fp);

    if (count > 0)
    {
        average = total / count;

        printf("\n========== SALES ANALYSIS ==========\n");

        printf("\nTotal Sales     : %.2f", total);
        printf("\nAverage Sale    : %.2f", average);
        printf("\nHighest Sale    : %.2f", highest);
        printf("\nLowest Sale     : %.2f", lowest);
        printf("\nNumber of Sales : %d\n", count);
    }
}

void generateReport()
{
    FILE *fp;
    FILE *report;
    struct Sale s;

    float total = 0;
    float average;
    int count = 0;

    fp = fopen("sales.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo sales data found.\n");
        return;
    }

    report = fopen("sales_report.txt", "w");

    if (report == NULL)
    {
        printf("\nReport file cannot be created.\n");
        fclose(fp);
        return;
    }

    fprintf(report, "========== SALES REPORT ==========\n\n");

    fprintf(report, "ID\tProduct\t\tAmount\n");
    fprintf(report, "--------------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        fprintf(report, "%d\t%-15s %.2f\n",
                s.id, s.product, s.amount);

        total = total + s.amount;
        count++;
    }

    if (count > 0)
    {
        average = total / count;

        fprintf(report, "\n========== SUMMARY ==========\n");
        fprintf(report, "Total Sales     : %.2f\n", total);
        fprintf(report, "Average Sale    : %.2f\n", average);
        fprintf(report, "Number of Sales : %d\n", count);
    }

    fclose(fp);
    fclose(report);

    printf("\nReport generated successfully!");
    printf("\nReport saved as: sales_report.txt\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n\n================================");
        printf("\n       SALES DATA ANALYSER");
        printf("\n================================");

        printf("\n1. Add Sales Data");
        printf("\n2. Display Sales Data");
        printf("\n3. Analyse Sales");
        printf("\n4. Generate Report");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addSale();
                break;

            case 2:
                displaySales();
                break;

            case 3:
                analyseSales();
                break;

            case 4:
                generateReport();
                break;

            case 5:
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}