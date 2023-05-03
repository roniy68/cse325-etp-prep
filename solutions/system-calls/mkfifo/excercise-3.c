#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_NAME "mypipe"

int main()
{
    int fd;
    char buffer[BUFSIZ];

    /* Create named pipe */
    mkfifo(FIFO_NAME, 0666);

    /* Open pipe for reading */
    fd = open(FIFO_NAME, O_RDONLY);

    /* Read from pipe */
    read(fd, buffer, BUFSIZ);

    /* Print data to standard output */
    printf("%s", buffer);

    /* Close pipe */
    close(fd);

    return 0;
}
