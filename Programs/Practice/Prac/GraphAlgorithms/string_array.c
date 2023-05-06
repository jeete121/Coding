#include <stdio.h>
#include <string.h>

int main()
{
    char str[100][100];

    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter %d string\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &str[i]);
    }
    printf("String array is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", str[i]);
    }
    return 0;
}