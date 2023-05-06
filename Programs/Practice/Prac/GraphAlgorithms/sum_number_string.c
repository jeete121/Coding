#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "hello123 67@ 98!23 78hh";

    int n = strlen(str);

    int i = 0;
    int sum = 0;
    while (str[i] != '\0')
    {
        //if the spaces
        while (str[i] != '\0' && str[i] == ' ')
        {
            i++;
        }

        //if not the digit
        while (str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'))
        {
            i++;
        }
        int num = 0;

        //if digit
        while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
        {
            num = num * 10 + str[i] - '0';
            i++;
        }
        sum += num;
    }
    printf("Sum of numbers in the string is %d", sum);
    return 0;
}