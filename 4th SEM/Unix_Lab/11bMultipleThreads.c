#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Function for threads to print "Hello world"
void *myNewThread(void *vargp) {
    printf("Hello world\n");
    return NULL;
}

// Function for threads to print their thread ID and check if it's the main thread
void *myThreadFun(void *vargp) {
    int *myid = (int *)vargp;
    printf("Thread ID: %ld, myid: %d\n", pthread_self(), *myid);

    // Check if the current thread is the main thread
    if (pthread_equal(pthread_self(), *myid)) {
        printf("Main thread encountered\n");
    }

    return NULL;
}

int main() {
    pthread_t tid;
    int i, j;

    // Create two threads using myThreadFun function
    for (i = 0; i < 2; i++) {
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
    }

    // Create 5 sets of 5 threads, each printing "Hello world"
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            pthread_create(&tid, NULL, myNewThread, NULL);
        }
    }

    // Wait for all threads to finish before exiting the program
    pthread_exit(NULL);

    return 0;
}
