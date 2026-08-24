#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char word[20], line[100];

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen("file.txt", "r");

    if(fp == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    while(fgets(line, sizeof(line), fp))
    {
        if(strstr(line, word))
            printf("%s", line);
    }

    fclose(fp);

    return 0;
}
