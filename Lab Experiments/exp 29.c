#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buffer[5], in = 0, out = 0;

sem_t empty, full;

void *producer(void *arg)
{
    int i;

    for(i = 1; i <= 5; i++)
    {
        sem_wait(&empty);

        buffer[in] = i;
        printf("Produced: %d\n", i);
        in = (in + 1) % 5;

        sem_post(&full);
    }

    return NULL;
}

void *consumer(void *arg)
{
    int i, item;

    for(i = 1; i <= 5; i++)
    {
        sem_wait(&full);

        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % 5;

        sem_post(&empty);
    }

    return NULL;
}

int main()
{
    pthread_t p, c;

    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
