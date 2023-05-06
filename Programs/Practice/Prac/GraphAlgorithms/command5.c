#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Enter a number ");
        return -1;
    }
    else
    {
        int num = atoi(argv[1]);
        int sum = 0;
        while (num > 0)
        {
            int temp = num % 10;
            sum += temp;
            num = num / 10;
        }
        printf("Sum of digits of number is %d", sum);
    }
    return 0;
}