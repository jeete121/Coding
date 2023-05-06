#include <stdio.h>
int main()
{
    char str[] = {'H', 'e', 'l', 'l', 'o'};
    int n = sizeof(str) / sizeof(str[0]);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = *(str + i);
        *(str + i) = *(str + n - i - 1);
        *(str + n - i - 1) = temp;
    }
    printf("String after reverse is : ");
    for (int i = 0; i < n; i++)
        printf("%c", str[i]);
}