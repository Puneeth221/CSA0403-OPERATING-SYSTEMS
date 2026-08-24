#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j, k;
    int faults = 0, hit, pos, farthest, next;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        hit = 0;

        /* Check for page hit */
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                hit = 1;
                break;
            }
        }

        /* Page fault */
        if(hit == 0)
        {
            faults++;

            /* Find empty frame */
            pos = -1;
            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            /* If no empty frame, find optimal page */
            if(pos == -1)
            {
                farthest = -1;

                for(j = 0; j < f; j++)
                {
                    next = -1;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                        {
                            next = k;
                            break;
                        }
                    }

                    /* Page not used again */
                    if(next == -1)
                    {
                        pos = j;
                        break;
                    }

                    if(next > farthest)
                    {
                        farthest = next;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
        }

        printf("\nPage %d: ", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}
