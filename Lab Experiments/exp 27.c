#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *file;

    dir = opendir(".");

    if(dir == NULL)
    {
        printf("Unable to open directory\n");
        return 1;
    }

    printf("Files and Directories:\n");

    while((file = readdir(dir)) != NULL)
    {
        printf("%s\n", file->d_name);
    }

    closedir(dir);

    return 0;
}
