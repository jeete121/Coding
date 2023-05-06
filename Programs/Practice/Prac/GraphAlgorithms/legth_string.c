#include <stdio.h>
int main()
{
    char str[] = "Hello World";
    int len = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    printf("Length of string is %d", len);
    return 0;
}