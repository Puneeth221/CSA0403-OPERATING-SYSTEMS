#include <stdio.h>

int main()
{
    int b[10], p[10], nb, np;
    int i, j, largest;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &p[i]);

    printf("\nProcess\tSize\tBlock\n");

    for(i = 0; i < np; i++)
    {
        largest = -1;

        for(j = 0; j < nb; j++)
        {
            if(b[j] >= p[i])
            {
                if(largest == -1 || b[j] > b[largest])
                    largest = j;
            }
        }

        if(largest != -1)
        {
            printf("P%d\t%d\tB%d\n", i + 1, p[i], largest + 1);
            b[largest] -= p[i];
        }
        else
        {
            printf("P%d\t%d\tNot Allocated\n", i + 1, p[i]);
        }
    }

    return 0;
}
