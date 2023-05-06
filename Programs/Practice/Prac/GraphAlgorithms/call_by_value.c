#include <stdio.h>

int sumOfTwo(int a, int b)
{
    int sum = a + b;
    return sum;
}
int main()
{
    int num1 = 10, num2 = 20;

    //call by value to find sum of
    //two numbers
    int sum = sumOfTwo(num1, num2);
    printf("Sum is %d", sum);
    return 0;
}