#include <stdio.h>
int main()
{
    int num;
    printf("Enter a three digit number : ");
    scanf("%d", &num);
    int sum = 0;
    int n = num;
    while (n > 0)
    {
        int temp = n % 10;
        sum = sum + temp;
        n = n / 10;
    }
    printf("Sum of digits of %d is %d ", num, sum);
    return 0;
}