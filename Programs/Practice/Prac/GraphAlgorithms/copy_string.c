#include <stdio.h>
int main()
{
    char str[1000];
    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);

    char copystr[1000];
    for (int i = 0; str[i] != '\0'; i++)
    {
        copystr[i] = str[i];
    }
    printf("Copy string is %s", copystr);
    return 0;
}