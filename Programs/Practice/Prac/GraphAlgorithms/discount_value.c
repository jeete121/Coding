#include <stdio.h>
int main()
{
    float amount;
    float discount;

    printf("Enter the original amount : ");
    scanf("%f", &amount);

    printf("Enter dicount percentage : ");
    scanf("%f", &discount);

    float final = amount - amount * discount / 100;

    float discountAmount = amount * discount / 100;
    printf("Final price is %f\n", final);
    printf("Discount amount is %f", discountAmount);

    return 0;
}