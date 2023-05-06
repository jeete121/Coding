#include <stdio.h>
#include <math.h>

int main()
{
    printf("Armstrong numbers are ");
    for (int i = 100; i <= 500; i++)
    {
        int num = i;
        int n = i;
        int sum = 0;
        while (n > 0)
        {
            int temp = n % 10;
            sum += pow(temp, 3);
            n = n / 10;
        }
        if (sum == num)
            printf("%d ", i);
    }
}