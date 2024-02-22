#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    for (int i = 0; i < 5; i++) {
        if (fork() == 0) {
            // Child process
            printf("[son] pid %d from [parent] pid %d\n", getpid(), getppid());
            exit(0);
        }
    }

    // Parent process
    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    return 0;
}
