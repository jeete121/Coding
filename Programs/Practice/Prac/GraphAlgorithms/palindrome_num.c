#include <stdio.h>
int main()
{
    int num = 121;
    int n = num;
    int rev = 0;
    while (n > 0)
    {
        int temp = n % 10;
        rev = rev * 10 + temp;
        n = n / 10;
    }
    if (num == rev)
    {
        printf("Number is palindrome ");
    }
    else
    {
        printf("Number is not palindrome ");
    }
    return 0;
}