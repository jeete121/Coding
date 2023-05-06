#include <stdio.h>

int main()
{
    char ch = 'B';

    if (ch >= 'A' && ch <= 'Z')
    {
        printf("Character is uppercase\n");
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        printf("Character is lowercase\n");
    }
    else if (ch >= '0' && ch <= '9')
    {
        printf("Character is digit\n");
    }
    else
    {
        printf("Character is special\n");
    }
    return 0;
}