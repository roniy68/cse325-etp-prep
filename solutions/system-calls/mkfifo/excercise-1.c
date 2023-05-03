#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

int main(void) {
    int fd;
    pid_t pid;
    char buf[100];

    // Create named pipe (FIFO)
    if (mkfifo(FIFO_NAME, 0666) < 0) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process reads from the pipe
        fd = open(FIFO_NAME, O_RDONLY);
        if (fd < 0) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        read(fd, buf, sizeof(buf));
        printf("Child: Received message: %s", buf);
        close(fd);
    } else {
        // Parent process writes to the pipe
        fd = open(FIFO_NAME, O_WRONLY);
        if (fd < 0) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        write(fd, "Hello, child!\n", 15);
        close(fd);
    }

    // Remove named pipe (FIFO)
    if (unlink(FIFO_NAME) < 0) {
        perror("unlink");
        exit(EXIT_FAILURE);
    }

    return 0;
}
