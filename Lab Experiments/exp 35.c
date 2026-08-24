#include <stdio.h>

int main()
{
    int index[50], n, i, block;

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter the block numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &index[i]);
    }

    printf("\nIndexed File Allocation:\n");

    printf("Index Block\n");
    printf("-----------\n");

    for(i = 0; i < n; i++)
    {
        printf("Index[%d] -> Block %d\n", i, index[i]);
    }

    printf("\nEnter index to access: ");
    scanf("%d", &i);

    if(i >= 0 && i < n)
    {
        block = index[i];
        printf("Index %d points to Block %d\n", i, block);
    }
    else
    {
        printf("Invalid index\n");
    }

    return 0;
}
