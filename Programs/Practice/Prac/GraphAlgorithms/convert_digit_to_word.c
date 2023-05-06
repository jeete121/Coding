#include <stdio.h>
#include <string.h>

void convertDigitsToWords(char str[11][100], int num)
{
    if (num < 10)
    {
        printf("%s ", str[num]);
        return;
    }
    else
    {
        convertDigitsToWords(str, num / 10);
        printf("%s ", str[num % 10]);
    }
}
int main()
{
    int num = 3214;

    char str[11][100] = {"Zero", "One", "Two",
                         "Three", "Four", "Five",
                         "Six", "Seven", "Eight",
                         "Nine"};

    convertDigitsToWords(str, num);
    return 0;
}