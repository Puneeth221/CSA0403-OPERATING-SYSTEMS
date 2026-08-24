#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char data[100];

    fd = open("file.txt", O_CREAT | O_RDWR, 0644);

    if(fd == -1)
    {
        printf("File cannot be opened\n");
        return 0;
    }

    write(fd, "Hello UNIX File", 15);

    lseek(fd, 0, SEEK_SET);

    read(fd, data, 15);
    data[15] = '\0';

    printf("File Content: %s\n", data);

    close(fd);

    printf("File created, written, read and closed successfully.\n");

    return 0;
}
