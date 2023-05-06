#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch[2001];
    FILE *fp;
    fp = fopen("hello.txt", "r");

    if (fp == NULL)
    {
        printf("File is  not opened\n");
        return -1;
    }

    //scan the first line of the file
    fscanf(fp, "%[^\n]", ch);
    printf("First line of the file :\n%s", ch);
    fclose(fp);
    return 0;
}