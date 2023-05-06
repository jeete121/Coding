#include <stdio.h>
int main()
{
    int num = 1234;
    int rev = 0;
    while (num > 0)
    {
        int temp = num % 10;
        rev = rev * 10 + temp;
        num = num / 10;
    }
    printf("reverse is %d", rev);
    return 0;
}