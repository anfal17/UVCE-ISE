#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int main(void) {
    pid_t pid;
    int *shared;
    int shmid;

    // Create a shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    printf("Shared Memory ID=%u\n", shmid);

    if ((fork()) == 0) {
        // Child process
        shared = shmat(shmid, (void *)0, 0);
        printf("Child pointer %p\n", shared);
        *shared = 1;
        printf("Child value=%d\n", *shared);
        sleep(2);
        printf("Child value=%d\n", *shared);
    } else {
        // Parent process
        shared = shmat(shmid, (void *)0, 0);
        printf("Parent pointer %p\n", shared);
        printf("Parent value=%d\n", *shared);
        sleep(1);
        *shared = 42;
        printf("Parent value=%d\n", *shared);
        sleep(5);
        // Remove the shared memory segment
        shmctl(shmid, IPC_RMID, 0);
    }

    return 0;
}
