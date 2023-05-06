#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    FILE *fp;
    fp = fopen("hello.txt", "w");

    if (fp == NULL)
    {
        printf("File is  not opened\n");
        return -1;
    }
    printf("Enter a line to add into the file:\n");
    fgets(str, sizeof(str), stdin);
    fprintf(fp, "%s", str);
    fclose(fp);
    return 0;
}