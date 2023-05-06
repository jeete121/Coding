#include <stdio.h>

int main()
{
    int num = 430140;

    int arr[100];
    int i = 0;
    while (num > 0)
    {
        int temp = num % 10;
        if (temp == 0)
        {
            temp = 1;
        }
        arr[i] = temp;
        i++;
        num = num / 10;
    }
    for (int j = i-1; j >= 0; j--)
    {
        num = num * 10 + arr[j];
    }

    printf("Number is %d", num);

    return 0;
}