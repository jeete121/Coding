#include <stdio.h>

int main()
{

    FILE *readFile;
    int num;
    char buffer[32] = {0};

    // creating a FILE pointer
    FILE *fptrWrite;

    // open the file in write mode
    fptrWrite = fopen("square.txt", "w");
    if (fptrWrite != NULL)
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
        int count = 0;
        printf("\nRead Numbers from file:\n");
        while (!feof(readFile))
        {
            fscanf(readFile, "%d", &num);
            sprintf(buffer, "%d\n", num * num);
            fputs(buffer, fptrWrite);
            count++;
            if (count == 10)
            {
                break;
            }
        }
        printf("\nEnd of file.\n");

        //close files
        fclose(readFile);
        fclose(fptrWrite);
    }
    return 0;
}