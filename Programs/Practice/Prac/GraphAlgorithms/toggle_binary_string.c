#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "10101101";

    //find length of string
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
        {
            str[i] = '0';
        }
        else
        {
            str[i] = '1';
        }
    }

    printf("Toggled string is ");
    printf("%s", str);
    return 0;
}