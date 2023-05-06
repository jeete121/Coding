#include <stdio.h>
int main()
{
    char str[] = "Hello   World";
    int n = sizeof(str) / sizeof(str[0]);
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        else
        {
            str[l] = str[i];
            l++;
        }
    }
    printf("String after remove space is %s\n", str);
    printf("Number of characters are %d\n", l - 1);

    return 0;
}