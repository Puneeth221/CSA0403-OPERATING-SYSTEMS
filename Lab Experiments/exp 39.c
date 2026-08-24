#include <stdio.h>
#include <stdlib.h>

int main()
{
    int request[50], n, head, disk_size, direction;
    int i, j, temp, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

    /* Sort requests */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nC-SCAN Disk Scheduling:\n");
    printf("%d", head);

    if(direction == 1)
    {
        /* Move towards right */
        for(i = 0; i < n; i++)
        {
            if(request[i] >= head)
            {
                total += abs(request[i] - head);
                head = request[i];
                printf(" -> %d", head);
            }
        }

        /* Go to end of disk */
        total += (disk_size - 1) - head;
        head = disk_size - 1;
        printf(" -> %d", head);

        /* Jump to beginning */
        total += disk_size - 1;
        head = 0;
        printf(" -> %d", head);

        /* Continue towards right */
        for(i = 0; i < n; i++)
        {
            if(request[i] < head)
                continue;

            if(request[i] != 0)
            {
                total += abs(request[i] - head);
                head = request[i];
                printf(" -> %d", head);
            }
        }
    }
    else
    {
        /* Move towards left */
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] <= head)
            {
                total += abs(request[i] - head);
                head = request[i];
                printf(" -> %d", head);
            }
        }

        /* Go to beginning of disk */
        total += head;
        head = 0;
        printf(" -> %d", head);

        /* Jump to end */
        total += disk_size - 1;
        head = disk_size - 1;
        printf(" -> %d", head);

        /* Continue towards left */
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] > head)
                continue;

            if(request[i] != disk_size - 1)
            {
                total += abs(request[i] - head);
                head = request[i];
                printf(" -> %d", head);
            }
        }
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", total);
    printf("Average Head Movement = %.2f cylinders\n",
           (float)total / n);

    return 0;
}
