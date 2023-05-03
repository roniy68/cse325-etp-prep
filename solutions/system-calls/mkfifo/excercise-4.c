#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_NAME "mypipe"

int main() {
    pid_t pid;
    int fd;
    char buffer[100];

    // create the named pipe
    mkfifo(FIFO_NAME, 0666);

    // fork the process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child process reads from the pipe
        fd = open(FIFO_NAME, O_RDONLY);
        read(fd, buffer, sizeof(buffer));
        printf("Child read from pipe: %s", buffer);
        close(fd);
        exit(EXIT_SUCCESS);
    } else {
        // parent process writes to the pipe
        fd = open(FIFO_NAME, O_WRONLY);
        write(fd, "Hello from parent\n", strlen("Hello from parent\n"));
        close(fd);
        wait(NULL);
    }

    return 0;
}
