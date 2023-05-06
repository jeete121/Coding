#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Hello   World";
    int n = strlen(str);
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
    printf("String after remove space is ");
    for (int i = 0; i < l; i++)
    {
        printf("%c", str[i]);
    }
    return 0;
}