#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    float sqrtvalue;
    printf("Enter a number : ");
    scanf("%d", &num);
    goto sqrtNum;

sqrtNum:
    sqrtvalue = (float)sqrt(num);
    printf("Sqrt of %d is %f", num, sqrtvalue);
    return 0;
}