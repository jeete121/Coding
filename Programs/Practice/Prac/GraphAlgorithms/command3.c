#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Enter two numbers ");
        return -1;
    }
    else
    {
        int firstNum = atoi(argv[1]);
        int secondNum = atoi(argv[2]);

        float average = (float)(firstNum + secondNum) / 2;
        printf("Average is %f", average);
    }
    return 0;
}