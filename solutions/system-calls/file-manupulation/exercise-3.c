#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int fd, n, count;
    char buffer[BUFFER_SIZE];

    // Open the input file
    fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the file and count the number of lines
    count = 0;
    while ((n = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < n; i++) {
            if (buffer[i] == '\n') {
                count++;
            }
        }
    }
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Close the input file
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    // Display the number of lines
    printf("Number of lines: %d\n", count);

    return 0;
}
