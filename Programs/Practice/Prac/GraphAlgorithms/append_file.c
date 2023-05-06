#include <stdio.h>

int main()
{

    FILE *file1, *file2, *mergeFile;
    char fileName1[1000];
    char fileName2[1000];
    char mergeFileName[1000];

    char c;
    printf("Enter first file name with full path: ");
    scanf("%s", fileName1);

    printf("Enter second file name with full path: ");
    scanf("%s", fileName2);

    printf("Enter merge file name with full path: ");
    scanf("%s", mergeFileName);

    //open file in read mode
    file1 = fopen(fileName1, "r");

    //open file in read mode
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
        // exit status
        return -1;
    }

    // first file
    c = getc(file1);
    while (c != EOF)
    {
        putc(c, mergeFile);
        c = getc(file1);
    }
    putc('\n', mergeFile);
    // second file
    c = getc(file2);
    while (c != EOF)
    {
        putc(c, mergeFile);
        c = getc(file2);
    }

    //close files
    fclose(file1);
    fclose(file2);
    fclose(mergeFile);

    return 0;
}
