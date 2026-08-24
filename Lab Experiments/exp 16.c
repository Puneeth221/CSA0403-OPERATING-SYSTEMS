#include <stdio.h>

struct employee
{
    int id;
    char name[20];
    float salary;
};

int main()
{
    FILE *fp;
    struct employee e;
    int n;

    fp = fopen("employee.dat", "w+");

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter ID, Name and Salary: ");
        scanf("%d %s %f", &e.id, e.name, &e.salary);

        fwrite(&e, sizeof(e), 1, fp);
    }

    printf("\nEnter employee number to access: ");
    scanf("%d", &n);

    fseek(fp, (n - 1) * sizeof(e), SEEK_SET);
    fread(&e, sizeof(e), 1, fp);

    printf("\nEmployee Details\n");
    printf("ID     : %d\n", e.id);
    printf("Name   : %s\n", e.name);
    printf("Salary : %.2f\n", e.salary);

    fclose(fp);

    return 0;
}
