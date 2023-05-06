#include <stdio.h>
#include <math.h>

int main()
{
    int binary[] = {1, 0, 1, 0};
    int decimal = 0;
    int len = sizeof(binary) / sizeof(binary[0]);
    for (int i = 0; i < len; i++)
    {
        decimal = decimal + binary[i] * pow(2, len - 1 - i);
    }
    printf("Decimal number is %d", decimal);
    return 0;
}