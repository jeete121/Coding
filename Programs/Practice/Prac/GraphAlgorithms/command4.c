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
        printf("Numbers before swap:\n");
        printf("First = %d, Second = %d\n", firstNum, secondNum);
        int temp = firstNum;
        firstNum = secondNum;
        secondNum = temp;
        printf("Numbers after swap:\n");
        printf("First = %d, Second = %d", firstNum, secondNum);
    }
    return 0;
}