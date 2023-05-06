#include <stdio.h>
int main()
{
    int base, power;
    int i;
    printf("Enter the base value : ");
    scanf("%d", &base);
    printf("Enter the power value : ");
    scanf("%d", &power);

    int powerAnwer = 1;
    for (i = 1; i <= power; i++)
    {
        powerAnwer = powerAnwer * base;
    }
    printf("Power is %d", powerAnwer);
    return 0;
}