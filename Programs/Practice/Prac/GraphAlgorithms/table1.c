#include <stdio.h>
int main()
{
    int num;
    int startlimit, endlimit, i;
    printf("Enter a number : ");
    scanf("%d", &num);
    printf("Enter start limit : ");
    scanf("%d", &startlimit);
    printf("Enter end limit : ");
    scanf("%d", &endlimit);
    for (i = startlimit; i <= endlimit; i++)
    {
        printf("%d X %d = %d\n", num, i, i * num);
    }
    return 0;
}