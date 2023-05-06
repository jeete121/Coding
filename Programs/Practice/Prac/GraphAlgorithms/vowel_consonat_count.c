#include <stdio.h>
int main()
{
    char str[] = "Hello 123 @ World";

    int consonant = 0, vowel = 0, other = 0, digits = 0;

    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowel++;
        }
        else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            vowel++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            consonant++;
        }

        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            consonant++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digits++;
        }
        else
        {
            other++;
        }
        i++;
    }
    printf("Consonant count is %d\n", consonant);

    printf("Vowel count is %d\n", vowel);

    printf("Digit count is %d\n", digits);

    printf("Other count is  %d\n", other);

    return 0;
}