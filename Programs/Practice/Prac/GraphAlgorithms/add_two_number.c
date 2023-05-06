#include <stdio.h>
int main()
{
    int fisrtNum, secondNum;
    printf("Enter first number : ");
    scanf("%d", &fisrtNum);
    printf("Enter second number : ");
    scanf("%d", &secondNum);
    int sum = fisrtNum + secondNum;
    printf("Sum of two numbers is %d", sum);
    return 0;
}