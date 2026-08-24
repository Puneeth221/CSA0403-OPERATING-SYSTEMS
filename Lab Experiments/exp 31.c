#include <stdio.h>

int main()
{
    int pages[20], frame[10];
    int n, f, i, j, k = 0, pageFault = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            frame[k] = pages[i];
            k = (k + 1) % f;
            pageFault++;
        }

        printf("\n%d\t", pages[i]);

        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", pageFault);

    return 0;
}
