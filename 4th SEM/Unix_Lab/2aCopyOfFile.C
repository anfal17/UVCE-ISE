#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// Function to copy and display the content of a file
void typefile(char *filename) {
    int fd, nread;
    char buf[1024];

    // Open the file for reading
    fd = open(filename, O_RDONLY);

    // Check if the file opened successfully
    if (fd == -1) {
        perror(filename);
        return;
    }

    // Read and write the file content
    while ((nread = read(fd, buf, sizeof(buf))) > 0)
        write(1, buf, nread);

    // Close the file
    close(fd);
}

// Main function to process command line arguments and call typefile
int main(int argc, char **argv) {
    int argno;

    // Loop through command line arguments (file names)
    for (argno = 1; argno < argc; argno++) {
        typefile(argv[argno]); // Call typefile function for each file
    }

    exit(0); // Exit the program
}

