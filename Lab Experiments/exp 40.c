#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat file;

    if (stat("sample.txt", &file) != 0)
    {
        printf("File not found!\n");
        return 1;
    }

    printf("File Access Permissions:\n");

    printf("Owner : ");
    printf("%c%c%c\n",
           (file.st_mode & S_IRUSR) ? 'r' : '-',
           (file.st_mode & S_IWUSR) ? 'w' : '-',
           (file.st_mode & S_IXUSR) ? 'x' : '-');

    printf("Group : ");
    printf("%c%c%c\n",
           (file.st_mode & S_IRGRP) ? 'r' : '-',
           (file.st_mode & S_IWGRP) ? 'w' : '-',
           (file.st_mode & S_IXGRP) ? 'x' : '-');

    printf("Others: ");
    printf("%c%c%c\n",
           (file.st_mode & S_IROTH) ? 'r' : '-',
           (file.st_mode & S_IWOTH) ? 'w' : '-',
           (file.st_mode & S_IXOTH) ? 'x' : '-');

    return 0;
}
