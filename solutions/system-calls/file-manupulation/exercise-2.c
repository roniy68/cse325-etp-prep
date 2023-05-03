#include <fcntl.h>
#include <unistd.h>

int main() {
    int input_fd = open("input.txt", O_RDONLY); // open the input file
    int output_fd = open("output.txt", O_CREAT | O_WRONLY, 0644); // create the output file
    char buf[1024];
    int num_read;
    while ((num_read = read(input_fd, buf, sizeof(buf))) > 0) { // read from input file
        write(output_fd, buf, num_read); // write to output file
    }
    close(input_fd); // close input file
    close(output_fd); // close output file
    return 0;
}
