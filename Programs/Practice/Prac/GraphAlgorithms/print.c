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
        printf("Number is %d", num);
    }
    return 0;
}