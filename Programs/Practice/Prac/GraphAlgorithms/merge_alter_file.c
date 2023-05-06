#include <stdio.h>

int main()
{

    FILE *file1, *file2, *mergeFile;
    char fileName1[1000];
    char fileName2[1000];
    char mergeFileName[1000];
    char c1;
    char c2;

    printf("Enter first file name with full path: ");
    scanf("%s", fileName1);

    printf("Enter second file name with full path: ");
    scanf("%s", fileName2);

    printf("Enter merge file name with full path: ");
    scanf("%s", mergeFileName);

    //open files in read mode
    file1 = fopen(fileName1, "r");
    file2 = fopen(fileName2, "r");
    if (file1 == NULL || file2 == NULL)
    {
        printf("Error in opening file \n");
        return -1;
    }

    //open file in write mode
    mergeFile = fopen(mergeFileName, "w");
    if (mergeFile != NULL)
    {
        printf("File created successfully!\n");
    }
    else
    {
        printf("Failed to create the file.\n");
        return -1;
    }

    char line[1000];

    c1 = fgetc(file1);

    c2 = fgetc(file2);

    int c = 0;
    //iterate till both we reach
    //end of any file
    while (c1 != EOF && c2 != EOF)
    {
        if (c1 != EOF)
        {
            ungetc(c1, file1);
            fgets(line, 1000, file1);
            fputs(line, mergeFile);
            c1 = fgetc(file1);
        }
        //put new line
        if (c1 == EOF)
        {
            putc('\n', mergeFile);
        }

        if (c2 != EOF)
        {

            ungetc(c2, file2);
            fgets(line, 1000, file2);
            fputs(line, mergeFile);
            c2 = fgetc(file2);
        }

        //put new line
        if (c2 == EOF)
        {
            putc('\n', mergeFile);
        }
    }
    //if first file remaining
    while (c1 != EOF)
    {
        ungetc(c1, file1);
        fgets(line, 1000, file1);
        fputs(line, mergeFile);
        c1 = fgetc(file1);
    }
    //if second file remaining
    while (c2 != EOF)
    {
        ungetc(c2, file2);
        fgets(line, 1000, file2);
        fputs(line, mergeFile);
        c2 = fgetc(file2);
    }
    //close files
    fclose(file1);
    fclose(file2);
    fclose(mergeFile);

    return 0;
}
