#include <stdio.h>

int main()
{

    FILE *readFile;

    //empty file have one
    //line
    int n = 0;
    char filename[10000];
    char ch;

    printf("Enter file name with full path: ");
    scanf("%s", filename);

    //open file in read mode
    readFile = fopen(filename, "r");
    if (readFile == NULL)
    {
        printf("Can't open file for %s\n", filename);
        return -1;
    }
    else
    {
        ch = getc(readFile);
        while (ch != EOF)
        {
            //if next line
            if (ch == '\n')
            {
                n = n + 1;
            }
            //take next character from file.
            ch = getc(readFile);
        }
    }
    //close the file
    fclose(readFile);

    printf("Total line is %d ", n);

    return 0;
}