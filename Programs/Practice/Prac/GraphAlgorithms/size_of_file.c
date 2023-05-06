#include <stdio.h>

int main()
{

    FILE *file;
    int size = 0;
    char fileName[100];

    printf("Enter first file name with full path: ");
    scanf("%s", fileName);

    //open file in read mode
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Error in opening file \n");
        return -1;
    }

    //file pointer at the end of file
    fseek(file, 0L, SEEK_END);

    //Take a position of file pointer in size variable
    size = ftell(file);

    printf("The size of given file is : %ld in bytes ", size);
    //close the file
    fclose(file);

    return 0;
}