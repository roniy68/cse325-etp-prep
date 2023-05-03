#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FILENAME "numbers.txt"
#define NUM_INTS 100

int main() {
    int fd, i, n;
    char buf[16];
    
    // Open the file for writing
    fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    
    // Write 100 integers to the file
    for (i = 0; i < NUM_INTS; i++) {
        sprintf(buf, "%d\n", i);
        if (write(fd, buf, strlen(buf)) < 0) {
            perror("write");
            exit(1);
        }
    }
    
    // Move the file pointer to the beginning of the file
    if (lseek(fd, 0, SEEK_SET) < 0) {
        perror("lseek");
        exit(1);
    }
    
    // Read and print the first 10 integers from the file
    printf("The first 10 integers in the file are:\n");
    for (i = 0; i < 10; i++) {
        if (read(fd, buf, 16) < 0) {
            perror("read");
            exit(1);
        }
        n = atoi(buf);
        printf("%d\n", n);
    }
    
    // Close the file
    if (close(fd) < 0) {
        perror("close");
        exit(1);
    }
    
    return 0;
}
