#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    printf("Enter coefficients of quadratic equation :");
    scanf("%d%d%d", &a, &b, &c);
    if (b * b - 4 * a * c < 0)
    {
        printf("Roots are imaginary ");
    }
    else
    {
        float root1 = (float)(-b + sqrt(b * b - 4 * a * c)) / 2 * a;
        float root2 = (float)(-b - sqrt(b * b - 4 * a * c)) / 2 * a;
        printf("Roots are: %f, %f ", root1, root2);
    }
    return 0;
}