#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "hello world";

    int n = strlen(str);

    int i = 0;
    while (str[i] != '\0')
    {
        while (str[i] != '\0' && str[i] == ' ')
        {
            i++;
        }
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        while (str[i] != '\0' && str[i] != ' ')
        {
            i++;
        }
        if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
        {
            str[i - 1] = str[i - 1] - 32;
        }
    }
    printf("String is %s", str);
    return 0;
}