#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];

    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);

    printf("String is %s ", str);

    return 0;
}