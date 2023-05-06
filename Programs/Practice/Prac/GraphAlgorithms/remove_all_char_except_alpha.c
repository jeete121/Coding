#include <stdio.h>
int main()
{
    char str[1000];
    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);
    int i = 0;
    int l = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[l] = str[i];
            i++;
            l++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[l] = str[i];
            i++;
            l++;
        }
        else
        {
            i++;
        }
    }

    printf("String after remove of all characters except alphabets is\n");
    for (int i = 0; i < l; i++)
    {
        printf("%c", str[i]);
    }

    return 0;
}