#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 25

int main(void) {
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if (pid > 0) {
        char input[BUFFER_SIZE];
        printf("Enter a message: ");
        fgets(input, BUFFER_SIZE, stdin);
        close(fd[0]); // Close unused read end of pipe
        write(fd[1], input, BUFFER_SIZE);
        close(fd[1]); // Close write end of pipe
    }
    else {
        char output[BUFFER_SIZE];
        close(fd[1]); // Close unused write end of pipe
        read(fd[0], output, BUFFER_SIZE);
        printf("Received message: %s", output);
        close(fd[0]); // Close read end of pipe
    }

    return 0;
}
