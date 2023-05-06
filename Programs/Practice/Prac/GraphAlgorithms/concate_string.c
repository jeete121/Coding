#include <stdio.h>
#include <string.h>
int main()
{
    char str1[2000] = "Hello", str2[] = " World";

    int i = 0;
    while (str1[i] != '\0')
    {
        ++i;
    }
    int j = 0;
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    printf("String after concate is ");
    puts(str1);

    return 0;
}