#include <stdio.h>
#include <string.h>

void sortString(char str[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}
int main()
{
    char str[] = "beingcodeexpert";

    int n = strlen(str);
    sortString(str, n);

    printf("Sorted string is %s", str);

    return 0;
}