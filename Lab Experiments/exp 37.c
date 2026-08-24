#include <stdio.h>
#include <stdlib.h>

int main()
{
    int request[50], n, head;
    int i, total = 0, distance;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Disk Scheduling:\n");
    printf("%d", head);

    for(i = 0; i < n; i++)
    {
        distance = abs(request[i] - head);
        total = total + distance;
        head = request[i];

        printf(" -> %d", request[i]);
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", total);
    printf("Average Head Movement = %.2f cylinders\n",
           (float)total / n);

    return 0;
}
