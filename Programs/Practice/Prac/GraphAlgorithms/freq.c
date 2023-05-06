#include <stdio.h>
int main()
{
    char str[1000], ch;
    int freq = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter a character : ");
    scanf("%c", &ch);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ch)
        {
            freq++;
        }
        i++;
    }
    printf("Frequecy of charcter %c is %d", ch, freq);
    return 0;
}