#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY, 0644); // create the file
    write(fd, "Hello, World!", 13); // write the text to the file
    close(fd); // close the file
    return 0;
}
