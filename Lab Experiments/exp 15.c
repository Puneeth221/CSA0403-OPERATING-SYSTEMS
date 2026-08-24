#include <stdio.h>

int main()
{
    int d, f, i, j;
    char file[10][10][20];

    printf("Enter number of directories: ");
    scanf("%d", &d);

    for(i = 0; i < d; i++)
    {
        printf("\nEnter number of files in Directory %d: ", i + 1);
        scanf("%d", &f);

        printf("Enter file names:\n");

        for(j = 0; j < f; j++)
            scanf("%s", file[i][j]);

        printf("Directory %d:\n", i + 1);

        for(j = 0; j < f; j++)
            printf("%s\n", file[i][j]);
    }

    return 0;
}
