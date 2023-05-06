#include <stdio.h>
int main()
{
    float firstNum, secondNum;

    printf("Enter first number : ");
    scanf("%f", &firstNum);

    printf("Enter second number : ");
    scanf("%f", &secondNum);

    float product = firstNum * secondNum;

    printf("Product is %f ", product);

    return 0;
}