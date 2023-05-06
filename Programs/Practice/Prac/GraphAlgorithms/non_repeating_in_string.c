#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Hello World";

    //find the length of string
    int n = strlen(str);
    int freq[256];
    for (int i = 0; i < 256; i++)
    {
        freq[i] = 0;
    }

    //find frequency of each characters in the
    //string
    for (int i = 0; i < n; i++)
    {
        freq[str[i]]++;
    }

    printf("Non Repeating characters are\n");
    for (int i = 0; i < n; i++)
    {
        if (freq[str[i]] == 1)
        {
            printf("%c ", str[i]);
        }
    }
    return 0;
}