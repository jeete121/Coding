#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    int n = strlen(s);
    int i = 0;
    while (i < n - 1)
    {
        char str[1001];
        int j = 0;
        while (i < n && s[i] != ' ')
        {
            str[j] = s[i];
            i++;
            j++;
        }

        while (s[i] == ' ')
        {
            i++;
        }
        for (int k = 0; k < j; k++)
        {
            printf("%c", str[k]);
        }
        printf("\n");
    }
    return 0;
}