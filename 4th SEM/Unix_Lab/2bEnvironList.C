#include<stdio.h>

int main(int argc, char* argv[]) {
    char **ptr;
    extern char **environ;

    // Loop through the environment list and print each entry
    for (ptr = environ; *ptr != 0; ptr++)
        printf("%s\n", *ptr);

    return 0;
}
