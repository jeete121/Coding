#include <stdio.h>
int main()
{
    int firstNum, secondNum, thirdNum;

    printf("Enter first number : ");
    scanf("%d", &firstNum);

    printf("Enter second number : ");
    scanf("%d", &secondNum);

    printf("Enter third number : ");
    scanf("%d", &thirdNum);

    if (firstNum >= secondNum)
    {
        if (firstNum >= thirdNum)
        {
            printf("First is greater ");
        }
        else
        {
            printf("Third is greater ");
        }
    }
    else
    {
        if (secondNum >= thirdNum)
        {
            printf("Second is greater ");
        }
        else
        {
            printf("Third is greater ");
        }
    }
    return 0;
}