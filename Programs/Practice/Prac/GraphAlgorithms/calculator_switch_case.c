#include <stdio.h>
int main()
{
    int firstNum, secondNum;
    char operator;

    printf("Enter any operator (+,-,*,/): ");
    scanf("%c", &operator);

    printf("Enter first number : ");
    scanf("%d", &firstNum);

    printf("Enter second number : ");
    scanf("%d", &secondNum);

    switch (operator)
    {
    case '+':
        printf("%d + %d is %d", firstNum, secondNum, firstNum + secondNum);
        break;
    case '-':
        printf("%d - %d is %d ", firstNum, secondNum, firstNum - secondNum);
        break;
    case '*':
        printf("%d * %d is %d ", firstNum, secondNum, firstNum * secondNum);
        break;
    case '/':
        printf("%d / %d is %f", firstNum, secondNum, (float)firstNum / secondNum);
        break;
    default:
        printf("Operator is not valid");
        break;
    }
}