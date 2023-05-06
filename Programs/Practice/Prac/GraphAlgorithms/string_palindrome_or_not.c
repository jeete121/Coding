#include <stdio.h>
int main()
{
    char str[] = {'H', 'e', 'e', 'l', 'e', 'e', 'H'};
    int n = sizeof(str) / sizeof(str[0]);

    int flag = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - 1 - i])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("String is palindrome ");
    else
        printf("String is not palindrome ");

    return 0;
}