#include <stdio.h>
#include <ctype.h>

int main()
{

    FILE *fileP, *tmpP;
    char fileName[100];
    char c;

    printf("Enter from file name with full path: ");
    scanf("%s", fileName);

    //open file in read mode
    fileP = fopen(fileName, "r");
    if (fileP == NULL)
    {
        printf("Error in opening file \n");
        return -1;
    }

    //open file in write mode
    tmpP = fopen("temp1.txt", "w");
    // first file
    c = getc(fileP);
    while (c != EOF)
    {

        putc(tolower(c), tmpP);
        c = getc(fileP);
    }
    fclose(fileP);
    fclose(tmpP);

    //remove from file
    remove(fileName);
    rename("temp1.txt", fileName);
    return 0;
}
