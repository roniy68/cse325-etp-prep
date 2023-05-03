#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FILENAME "input.txt"
#define BUFFER_SIZE 11  // 10 characters + null terminator

int main() {
    char buffer[BUFFER_SIZE];
    int fd, n;

    // Open the file for reading only
    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Move the file pointer to the end of the file
    off_t end = lseek(fd, 0, SEEK_END);
    if (end == -1) {
        perror("lseek");
        exit(1);
    }

    // Read the last 10 characters of the file
    off_t pos = lseek(fd, end - 10, SEEK_SET);
    if (pos == -1) {
        perror("lseek");
        exit(1);
    }
    n = read(fd, buffer, 10);
    if (n == -1) {
        perror("read");
        exit(1);
    }
    buffer[n] = '\0';

    // Print the last 10 characters of the file
    printf("Last 10 characters of \"%s\":\n", FILENAME);
    printf("%s\n", buffer);

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    return 0;
}
