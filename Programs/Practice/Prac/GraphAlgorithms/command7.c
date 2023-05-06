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
        if (num % 2 == 0)
        {
            printf("Number is even ");
        }
        else
        {
            printf("Number is odd ");
        }
    }
    return 0;
}