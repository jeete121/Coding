#include <stdio.h>
#include <stdbool.h>

int main()
{

    char str[] = "Hello 123 @ World!";

    int number = 123;

    char ch = 'A';

    FILE *fp;
    int i;

    fp = fopen(__FILE__, "r");
    while (true)
    {
        i = getc(fp);
        if (i == EOF)
        {
            break;
        }
        putchar(i);
    }

    fclose(fp);
    return 0;
}