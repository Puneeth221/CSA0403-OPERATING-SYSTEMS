#include <stdio.h>
#include <pthread.h>

void *fun(void *arg)
{
    printf("Thread is created\n");
    return NULL;
}

int main()
{
    pthread_t t;

    pthread_create(&t, NULL, fun, NULL);

    return 0;
}

#include <stdio.h>
#include <pthread.h>

void *fun(void *arg)
{
    printf("Thread is running\n");
    return NULL;
}

int main()
{
    pthread_t t;

    pthread_create(&t, NULL, fun, NULL);
    pthread_join(t, NULL);

    printf("Thread completed\n");

    return 0;
}


#include <stdio.h>
#include <pthread.h>

void *fun(void *arg)
{
    printf("Thread is running\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t t;

    pthread_create(&t, NULL, fun, NULL);
    pthread_join(t, NULL);

    printf("Thread exited successfully\n");

    return 0;
}
