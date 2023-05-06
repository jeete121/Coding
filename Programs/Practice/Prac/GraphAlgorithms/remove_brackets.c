#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "{(a+b)+d+e+(e*f)}";
    char newString[1000];

    int n = strlen(str);

    int len = 0, i = 0;
    while (i < n)
    {
        if (str[i] == '(' || str[i] == ')')
        {
            i++;
        }
        else if (str[i] == '{' || str[i] == '}')
        {
            i++;
        }
        else if (str[i] == '[' || str[i] == ']')
        {
            i++;
        }
        else
        {
            newString[len] = str[i];
            i++;
            len++;
        }
    }
    newString[len] = '\0';
    printf("String after remove of brackets is %s", newString);
    return 0;
}