#include <stdio.h>
int main()
{
    int reading;
    printf("Enter reading of bill : ");
    scanf("%d", &reading);
    if (reading <= 200)
    {
        int amount = 500;
        printf("Charge for %d reading is %d\n", reading, amount);
    }
    else if (reading > 200 && reading <= 400)
    {
        int amount = 3 * reading;
        printf("Charge for %d reading is %d\n", reading, amount);
    }
    else if (reading > 400 && reading <= 600)
    {
        int amount = 4 * reading;
        printf("Charge for %d reading is %d\n", reading, amount);
    }
    else if (reading > 600)
    {
        int amount = 5 * reading;
        printf("Charge for %d reading is %d\n", reading, amount);
    }
    return 0;
}