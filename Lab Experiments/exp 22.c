#include <stdio.h>

int main()
{
    int b[10], p[10], nb, np;
    int i, j, best;

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
        best = -1;

        for(j = 0; j < nb; j++)
        {
            if(b[j] >= p[i])
            {
                if(best == -1 || b[j] < b[best])
                    best = j;
            }
        }

        if(best != -1)
        {
            printf("P%d\t%d\tB%d\n", i + 1, p[i], best + 1);
            b[best] -= p[i];
        }
        else
        {
            printf("P%d\t%d\tNot Allocated\n", i + 1, p[i]);
        }
    }

    return 0;
}
