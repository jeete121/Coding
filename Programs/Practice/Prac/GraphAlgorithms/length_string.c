#include <stdio.h>
#include <string.h>

int main()
{
    char str[1001];

    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);

    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }

    printf("Length of string is %d ", length);
    return 0;
}