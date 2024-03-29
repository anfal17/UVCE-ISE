#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAXSIZE 10
#define FIFO_NAME "myfifo"

int main() {
    int fd, n;
    char *r;

    system("clear");
    r = (char *)malloc(sizeof(char) * MAXSIZE);
    int open_mode = O_RDONLY;

    if ((fd = open(FIFO_NAME, open_mode)) < 0) {
        printf("\nError: Named pipe cannot be opened\n");
        exit(0);
    }

    while (1) {
        n = read(fd, r, MAXSIZE);
        if (n > 0)
            printf("\nConsumer read: %s", r);
    }

    return 0;
}
