#include <stdio.h>

void reverseRec(char *str, int n)
{
    if (n == 1)
    {
        printf("%c", str[n - 1]);
    }
    else
    {
        printf("%c", str[n - 1]);
        reverseRec(str, n - 1);
    }
}
int main()
{
    char str[1000];

    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        len++;
    }
    printf("Reverse of string is : ");
    reverseRec(str, len);
    return 0;
}