#include <stdio.h>
int main()
{
    int firstNum, secondNum;
    printf("Enter first number : ");
    scanf("%d", &firstNum);
    printf("Enter second number : ");
    scanf("%d", &secondNum);
    printf("Numbers before swap is first= %d, second= %d\n", firstNum, secondNum);
    firstNum = firstNum * secondNum;
    secondNum = firstNum / secondNum;
    firstNum = firstNum / secondNum;
    printf("Numbers after swap is first= %d, second= %d\n", firstNum, secondNum);
    return 0;
}
