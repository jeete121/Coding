#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int firstNum, secondNum;
    int factorial = 1;
    
    if (argc!= 3)
    {
        printf("Please enter two numbers ");
        return -1;
    }
    else
    {
        firstNum = atoi(argv[1]);
        secondNum = atoi(argv[2]);
        int sum = firstNum + secondNum;
        printf("Sum is %d", sum);
    }
    return 0;
}