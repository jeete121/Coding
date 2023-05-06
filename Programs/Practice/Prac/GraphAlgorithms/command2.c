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

        if (firstNum == secondNum)
            printf("Both are equal");
        else if (firstNum < secondNum)
            printf("Smallest is %d", firstNum);
        else if (secondNum < firstNum)
            printf("Smallest is %d", secondNum);
    }
    return 0;
}