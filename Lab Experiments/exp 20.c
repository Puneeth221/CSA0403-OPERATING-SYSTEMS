#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int data = 0;
int readers = 0;

sem_t mutex, write;

void *reader(void *arg)
{
    sem_wait(&mutex);
    readers++;
    if(readers == 1)
        sem_wait(&write);
    sem_post(&mutex);

    printf("Reader %d is reading data = %d\n", *(int *)arg, data);

    sem_wait(&mutex);
    readers--;
    if(readers == 0)
        sem_post(&write);
    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg)
{
    sem_wait(&write);

    data++;
    printf("Writer is writing data = %d\n", data);

    sem_post(&write);

    return NULL;
}

int main()
{
    pthread_t r1, r2, w1;
    int a = 1, b = 2;

    sem_init(&mutex, 0, 1);
    sem_init(&write, 0, 1);

    pthread_create(&r1, NULL, reader, &a);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_create(&r2, NULL, reader, &b);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);

    sem_destroy(&mutex);
    sem_destroy(&write);

    return 0;
}
