#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main() {
    int fd, nread, pos;
    char buf[BUFSIZE];

    fd = open("input.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    pos = lseek(fd, 0, SEEK_END);
    if (pos < 0) {
        perror("lseek");
        exit(1);
    }

    pos = lseek(fd, 0, SEEK_SET);
    if (pos < 0) {
        perror("lseek");
        exit(1);
    }

    nread = read(fd, buf, pos/2);
    if (nread < 0) {
        perror("read");
        exit(1);
    }

    write(STDOUT_FILENO, buf, nread);

    close(fd);

    return 0;
}
