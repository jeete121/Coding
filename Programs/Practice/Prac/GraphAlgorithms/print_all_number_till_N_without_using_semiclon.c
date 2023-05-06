#include <stdio.h>
#define N 8

int main(int num, char *argv[])
{
    while (num <= N && printf("%d ", num) && num)
    {
        num++;
    }
}