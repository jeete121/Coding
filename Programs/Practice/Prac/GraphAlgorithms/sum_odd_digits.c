#include <stdio.h>

int sumOfOdd(int num)
{
    int sum = 0;
    while (num > 0)
    {
        int temp = num % 10;
        if (temp % 2 == 1)
            sum += temp;
        num = num / 10;
    }
    return sum;
}
int main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    int sum = sumOfOdd(num);
    printf("Sum of odd digits is %d", sum);

    return 0;
}