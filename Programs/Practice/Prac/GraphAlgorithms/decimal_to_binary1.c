#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int binary[100];
    int i = 0;
    while (num > 0)
    {
        int temp = num % 2;
        binary[i] = temp;
        num = num / 2;
        i++;
    }
    printf("Binary number is :");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
    return 0;
}