#include <stdio.h>

int main()
{

    FILE *fromFile, *toFile;
    char fromFileName[1000];
    char toFileName[1000];
    char ch;

    printf("Enter from file name with full path: ");
    scanf("%s", fromFileName);

    printf("Enter to file name with full path: ");
    scanf("%s", toFileName);

    fromFile = fopen(fromFileName, "r");
    if (fromFile == NULL)
    {
        printf("Error in opening file \n");
        return -1;
    }
    toFile = fopen(toFileName, "w");
    if (toFile != NULL)
    {
        printf("File created successfully!\n");
    }
    else
    {
        printf("Failed to create the file.\n");
        return -1;
    }
    // first file
    ch = getc(fromFile);
    while (ch != EOF)
    {

        putc(ch, toFile);
        ch = getc(fromFile);
    }

    //close the files
    fclose(fromFile);
    fclose(toFile);

    return 0;
}
