#include <stdio.h>

struct Block
{
    int data;
    int next;
};

int main()
{
    struct Block block[50];
    int n, i, first, current;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block data:\n");
    for(i = 0; i < n; i++)
    {
        printf("Block %d data: ", i);
        scanf("%d", &block[i].data);
    }

    printf("\nEnter next block number for each block (-1 for last):\n");
    for(i = 0; i < n; i++)
    {
        printf("Next of Block %d: ", i);
        scanf("%d", &block[i].next);
    }

    printf("\nEnter first block number: ");
    scanf("%d", &first);

    printf("\nLinked File Allocation:\n");

    current = first;

    while(current != -1)
    {
        printf("Block %d -> Data: %d",
               current, block[current].data);

        if(block[current].next != -1)
            printf(" -> ");

        current = block[current].next;
    }

    printf("\n");

    return 0;
}
