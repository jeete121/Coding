#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>

int main()
{
    int n;

    FILE *readFile;
    int num;
    char buffer[32] = {0};

    // creating a FILE pointer
    FILE *fptrWrite;

    // open the file in write mode
    fptrWrite = fopen("prime.txt", "w");
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

    printf("Enter a number : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            continue;
        }
        else
        {
            int flag = 0;
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                sprintf(buffer, "%d\n", i);
                fputs(buffer, fptrWrite);
            }
        }
    }
    fclose(fptrWrite);
    readFile = fopen("prime.txt", "r");

    if (readFile == NULL)
    {
        printf("Can't open file for prime.txt file.\n");
        return -1;
    }
    else
    {
        printf("\nRead Numbers from file:\n");
        while (!feof(readFile))
        {
            fscanf(readFile, "%d", &num);
            sprintf(buffer, "%d\n", num);
            printf("%d ", num);
        }
        printf("\nEnd of file.\n");

        //close files
        fclose(readFile);
    }
    return 0;
}