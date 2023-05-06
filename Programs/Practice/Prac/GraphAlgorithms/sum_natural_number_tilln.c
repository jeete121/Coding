#include <stdio.h>
int main()
{
    int num;
    int i;
    int sum = 0;
    printf("Enter a number : ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        sum = sum + i;
    }
    printf("Sum of natural number from 1 to %d is %d ", num, sum);
    return 0;
}