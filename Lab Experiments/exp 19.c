#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t lock;

void *process(void *arg)
{
    int i;

    for(i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&lock);

        count++;
        printf("Process %d: Count = %d\n", *(int *)arg, count);

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int p1 = 1, p2 = 2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, process, &p1);
    pthread_create(&t2, NULL, process, &p2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("\nFinal Count = %d\n", count);

    return 0;
}
