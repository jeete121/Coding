#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    if (num == 0)
    {
        printf("Neither negative nor positive\n");
    }
    else if (num > 0)
    {
        printf("Number is positive\n");
    }
    else
    {
        printf("Number is negative\n");
    }
    return 0;
}