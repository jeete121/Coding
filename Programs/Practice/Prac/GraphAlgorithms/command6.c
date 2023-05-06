#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Enter a number: ");
        return -1;
    }
    else
    {
        int num = atoi(argv[1]);
        int sum = 0;
        int n = num;
        while (n > 0)
        {
            int temp = n % 10;
            sum += pow(temp, 3);
            n = n / 10;
        }
        if (sum == num)
        {
            printf("Number is armstrong ");
        }
        else
        {
            printf("Number is not armstrong ");
        }
    }
    return 0;
}