#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static int x __attribute__((aligned (64)));
static int y __attribute__((aligned (64)));

void *thread_func1(void *param)
{
    for(int i = 0;i < 1000000000; ++i)
        x++;

        return NULL;
}

void *thread_func2(void  *param)
{
    volatile int c;
    for(int i = 0;i < 1000000000; ++i)
        c = y;

        return NULL;
}

int main()
{
    pthread_t tid1,tid2;

    pthread_create(&tid1, NULL, thread_func1, NULL);
    pthread_create(&tid2, NULL, thread_func2, NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2, NULL);
}