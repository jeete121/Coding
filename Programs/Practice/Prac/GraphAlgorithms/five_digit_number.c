#include <stdio.h>
int main()
{
    int num;
    printf("Enter a five digit number : ");
    scanf("%d", &num);

    int arr[6];
    int i = 4;
    while (num > 0)
    {
        arr[i] = num % 10;
        num = num / 10;
        i--;
    }
    for (i = 0; i < 5; i++)
        printf("%d\n", arr[i]);
    return 0;
}