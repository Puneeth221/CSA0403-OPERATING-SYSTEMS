#include <stdio.h>

int main()
{
    int frames[10], pages[50], time[10];
    int n, f, i, j, k, pos, min, faults = 0, hit;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        hit = 0;

        /* Check whether page is already present */
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                hit = 1;
                time[j] = i;
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

            /* If no empty frame, find LRU page */
            if(pos == -1)
            {
                min = time[0];
                pos = 0;

                for(k = 1; k < f; k++)
                {
                    if(time[k] < min)
                    {
                        min = time[k];
                        pos = k;
                    }
                }
            }

            frames[pos] = pages[i];
            time[pos] = i;
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
