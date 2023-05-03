#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_NAME "mypipe"

int main()
{
    int fd;
    char buf[256];

    // create the named pipe
    if (mkfifo(FIFO_NAME, 0666) < 0) {
        perror("mkfifo");
        exit(1);
    }

    // open the pipe for writing
    if ((fd = open(FIFO_NAME, O_WRONLY)) < 0) {
        perror("open");
        exit(1);
    }

    // write some data to the pipe
    sprintf(buf, "Hello, world!");
    write(fd, buf, sizeof(buf));

    // close the pipe
    close(fd);

    return 0;
}
