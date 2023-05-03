#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *dp;
    struct stat statbuf;
    char path[100];
    int num_files = 0;
    int num_dirs = 0;
    
    // open the directory
    dir = opendir("my_directory");
    if (dir == NULL) {
        printf("Error: Could not open directory\n");
        return 1;
    }
    
    // read the directory and print information about each file/directory
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            sprintf(path, "%s/%s", "my_directory", dp->d_name);
            stat(path, &statbuf);
            if (S_ISDIR(statbuf.st_mode)) {
                printf("Directory: %s\n", dp->d_name);
                num_dirs++;
            }
            else {
                printf("File: %s\n", dp->d_name);
                num_files++;
            }
        }
    }
    
    // display the number of files and directories
    printf("Number of files: %d\n", num_files);
    printf("Number of directories: %d\n", num_dirs);
    
    // close the directory
    closedir(dir);
    return 0;
}
