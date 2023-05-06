#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{

    int i = n - 1;
    while (i > 0 && strcmp(s[i - 1], s[i]) >= 0)
    {
        i--;
    }
    if (i <= 0)
        return 0;

    // Swap key with its successor in suffix
    int j = n - 1;
    while (strcmp(s[i - 1], s[j]) >= 0)
    {
        j--;
    }
    char *tmp = s[i - 1];
    s[i - 1] = s[j];
    s[j] = tmp;

    // Reverse the string
    j = n - 1;
    while (i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }

    return 1;
}

int main()
{
    char **s;
    int n = 2;
    s = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        s[i] = calloc(11, sizeof(char));
    }
    s[0] = "ab";
    s[1] = "cd";
    do
    {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    } while (next_permutation(n, s));
    for (int i = 0; i < n; i++)
        free(s[i]);
    free(s);
    return 0;
}