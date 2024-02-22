#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void* myturn(void *arg)
{
    for (int i = 1; i <= 20; i++)
    {
        sleep(1);
        printf("process 1: i=%d\n", i);
    }
    return NULL;
}

void yourturn()
{
    for (int i = 1; i <= 10; i++)
    {
        sleep(2);
        printf("process 2: j=%d\n", i);
    }
}

int main()
{
    pthread_t newthread;

    // Create a new thread (newthread) and execute myturn function
    pthread_create(&newthread, NULL, myturn, NULL);

    // Execute yourturn function in the main thread
    yourturn();

    // Wait for the newthread to finish before proceeding
    pthread_join(newthread, NULL);

    return 0;
}
