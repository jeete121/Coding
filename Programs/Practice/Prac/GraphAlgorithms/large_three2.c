#include <stdio.h>
int main()
{
    int firstNum, seondNum, thirdNum;

    printf("Enter first number : ");
    scanf("%d", &firstNum);

    printf("Enter second number : ");
    scanf("%d", &seondNum);

    printf("Enter third number : ");
    scanf("%d", &thirdNum);

    int maximum = firstNum > seondNum   ? (firstNum > thirdNum ? firstNum : thirdNum)
                  : seondNum > thirdNum ? seondNum
                                        : thirdNum;

    printf("Largest is %d ", maximum);
    return 0;
}