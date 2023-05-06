#include <stdio.h>
#include <math.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int n = num, sum = 0;
    while (n > 0)
    {
        int temp = n % 10;
        sum += pow(temp, 3);
        n = n / 10;
    }
    if (sum == num)
        printf("Number is Armstrong ");
    else
        printf("Number is not Armstrong ");

    return 0;
}