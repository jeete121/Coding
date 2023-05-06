#include <stdio.h>

int main()
{

    FILE *readFile;
    int num;
    char buffer[32] = {0};

    // creating a FILE pointer
    FILE *oddfile, *evenfile;

    // open the file in write mode
    oddfile = fopen("odd.txt", "w");
    evenfile = fopen("even.txt", "w");
    if (oddfile != NULL && evenfile != NULL)
    {
        printf("File created successfully!\n");
    }
    else
    {
        printf("Failed to create the file.\n");
        // exit status for OS that an error occurred
        return -1;
    }

    readFile = fopen("hello.txt", "r");

    if (readFile == NULL)
    {
        printf("Can't open file for integers.txt file.\n");
        return -1;
    }
    else
    {
        printf("\nRead Numbers from file:\n");
        while (!feof(readFile))
        {
            fscanf(readFile, "%d", &num);
            sprintf(buffer, "%d\n", num);
            if (num % 2 == 0)
            {
                fputs(buffer, evenfile);
            }
            else
            {
                fputs(buffer, oddfile);
            }
        }
        printf("\nEnd of file.\n");

        //close files
        fclose(readFile);
        fclose(oddfile);
        fclose(evenfile);
    }
    return 0;
}