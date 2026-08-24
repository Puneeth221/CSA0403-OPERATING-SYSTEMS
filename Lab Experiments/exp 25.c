#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    int fd;
    struct stat s;
    DIR *d;
    struct dirent *file;

    fd = open("test.txt", O_CREAT | O_RDWR, 0644);

    fcntl(fd, F_SETFL, O_APPEND);
    printf("fcntl() executed\n");

    lseek(fd, 0, SEEK_END);
    printf("lseek() executed\n");

    stat("test.txt", &s);
    printf("File Size: %ld bytes\n", s.st_size);

    d = opendir(".");
    printf("\nFiles in directory:\n");

    while((file = readdir(d)) != NULL)
        printf("%s\n", file->d_name);

    closedir(d);
    close(fd);

    return 0;
}
