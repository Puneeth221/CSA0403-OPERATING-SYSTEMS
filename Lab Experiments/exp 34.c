#include <stdio.h>

int main()
{
    int records[50], n, i, search, found = 0;

    printf("Enter number of records: ");
    scanf("%d", &n);

    printf("Enter the records:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &records[i]);
    }

    printf("\nRecords in sequential order:\n");
    for(i = 0; i < n; i++)
    {
        printf("Record %d: %d\n", i + 1, records[i]);
    }

    printf("\nEnter record to search: ");
    scanf("%d", &search);

    /* Sequential access */
    for(i = 0; i < n; i++)
    {
        printf("Reading Record %d...\n", i + 1);

        if(records[i] == search)
        {
            printf("Record %d found at position %d\n",
                   search, i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Record not found\n");

    return 0;
}
