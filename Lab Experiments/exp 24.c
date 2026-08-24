#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char data[100];

    fd = open("file.txt", O_CREAT | O_RDWR, 0644);

    write(fd, "Hello UNIX", 10);

    lseek(fd, 0, SEEK_SET);

    read(fd, data, 10);
    data[10] = '\0';

    printf("File Content: %s\n", data);

    close(fd);

    return 0;
}
