#include <stdio.h>
int main()
{
    int firstNum, secondNum;
    printf("Enter first number : ");
    scanf("%d", &firstNum);
    printf("Enter second number : ");
    scanf("%d", &secondNum);
    printf("Numbers before swap is first= %d, second= %d\n", firstNum, secondNum);
    int thirdNum = firstNum;
    firstNum = secondNum;
    secondNum = thirdNum;
    printf("Numbers after swap is first= %d, second= %d\n", firstNum, secondNum);
    return 0;
}