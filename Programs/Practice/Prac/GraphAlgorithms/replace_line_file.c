#include <stdio.h>
#include <stdbool.h>

int main()
{
    FILE *fileptr1, *fileptr2;
    char filechar[4000];
    char ch;
    int lineNum, count = 1;

    printf("Enter file name: ");
    scanf("%s", filechar);

    //open file in read mode
    fileptr1 = fopen(filechar, "r");

    ch = getc(fileptr1);
    //print the contents of file .
    while (true)
    {

        printf("%c", ch);
        ch = getc(fileptr1);
        if (ch == EOF)
        {
            break;
        }
    }
    printf("\n");
    printf("Enter line number to be deleted : ");
    scanf("%d", &lineNum);

    //take fileptr1 to start point of the
    //file
    rewind(fileptr1);

    //open file in read mode
    fileptr2 = fopen("temp.txt", "w");

    ch = getc(fileptr1);
    while (true)
    {

        if (ch == EOF)
        {
            break;
        }
        //if new line then count lines count
        if (ch == '\n')
        {
            count++;
        }

        //copy the content to other file
        //before the line number to be deleted
        if (count != lineNum)
        {
            putc(ch, fileptr2);
        }
        else
        {

            //delete the current line

            while ((ch = getc(fileptr1)) != '\n')
            {
                
            }
      

            //insert new line
            fputs("\n", fileptr2);
            count++;
        }
        //continue till EOF is encountered
        ch = getc(fileptr1);
    }
    //close the files
    fclose(fileptr1);
    fclose(fileptr2);

    //remove from file
    remove(filechar);
    rename("temp.txt", filechar);

    //open file in read mode
    fileptr1 = fopen(filechar, "r");
    //reads the character from file

    ch = getc(fileptr1);
    //until last character of file is encountered

    while (true)
    {

        if (ch == EOF)
        {
            break;
        }
        else
        {
            printf("%c", ch);
            ch = getc(fileptr1);
        }
    }
    //close the file
    fclose(fileptr1);

    return 0;
}