#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];

    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);

    int length = strlen(str);

    printf("Length of string is %d", length);
    return 0;
}