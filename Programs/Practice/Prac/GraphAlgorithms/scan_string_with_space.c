#include <stdio.h>

int main()
{
    char str[1000];

    printf("Enter a sentence : ");
    scanf("%[^\n]%*c", str);
    printf("Your sentence is\n", str);
    printf("%s", str);
    return 0;
}
