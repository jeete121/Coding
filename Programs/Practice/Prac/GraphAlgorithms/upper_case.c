#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "beingcodeexpert";

    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }

    printf("String in upper case is %s", str);
    return 0;
}