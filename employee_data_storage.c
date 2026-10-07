#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee
{
    char name[50];
    int id;
    char department[50];
    float salary;
};
void addEmployee()
{
    struct employee emp;
    FILE *fp = fopen("employee.dat", "ab");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEmployee name: ");
    scanf(" %49[^\n]", emp.name);

    printf("Employee ID: ");
    scanf("%d", &emp.id);

    printf("Department: ");
    scanf(" %49[^\n]", emp.department);

    printf("Employee salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(emp), 1, fp);
    fclose(fp);

    printf("Employee added successfully.\n");
}


void displayEmployees()
{
    
    struct employee emp;
    FILE *fp;
    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("No employee records found.\n");
        return;
    }

    printf("\n--- Employee Records ---\n");

    while (fread(&emp, sizeof(emp), 1, fp) == 1)
    {
        printf("\nID     : %d", emp.id);
        printf("\nName   : %s", emp.name);
        printf("\nSalary : %.2f\n", emp.salary);
    }

    fclose(fp);
}

void searchEmployee()
{
    FILE *fp;
    struct employee emp;
    int id, found = 0;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("No employee records found.\n");
        return;
    }

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(emp), 1, fp) == 1)
    {
        if (emp.id == id)
        {
            printf("\nEmployee Found!");
            printf("\nID     : %d", emp.id);
            printf("\nName   : %s", emp.name);
            printf("\nSalary : %.2f\n", emp.salary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Employee not found.\n");
    }

    fclose(fp);
}

void updateEmployee()
{
    FILE *fp;
    struct employee emp;
    int id, found = 0;

    fp = fopen("employee.dat", "rb+");

    if (fp == NULL)
    {
        printf("No employee records found.\n");
        return;
    }

    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(emp), 1, fp) == 1)
    {
        if (emp.id == id)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]", emp.name);

            printf("Enter new salary: ");
            scanf("%f", &emp.salary);

            fseek(fp, -sizeof(emp), SEEK_CUR);
            fwrite(&emp, sizeof(emp), 1, fp);

            printf("Employee updated successfully.\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Employee not found.\n");
    }

    fclose(fp);
}

void deleteEmployee()
{
    FILE *fp, *temp;
    struct employee emp;
    int id, found = 0;

    fp = fopen("employee.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(emp), 1, fp) == 1)
    {
        if (emp.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&emp, sizeof(emp), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found == 1)
    {
        printf("Employee deleted successfully.\n");
    }
    else
    {
        printf("Employee not found.\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\n===== EMPLOYEE MANAGEMENT SYSTEM =====");
        printf("\n1. Add Employee");
        printf("\n2. Display Employees");
        printf("\n3. Search Employee");
        printf("\n4. Update Employee");
        printf("\n5. Delete Employee");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee();
            break;

        case 2:
            displayEmployees();
            break;

        case 3:
            searchEmployee();
            break;

        case 4:
            updateEmployee();
            break;

        case 5:
            deleteEmployee();
            break;

        case 6:
            printf("Program ended.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
