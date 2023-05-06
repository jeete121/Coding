#include <stdio.h>
#include <math.h>

int main()
{
    int start, end;
    printf("Enter a starting number : ");
    scanf("%d", &start);

    printf("Enter a ending number : ");
    scanf("%d", &end);

    printf("Armstrong number from %d to %d are:\n", start, end);
    for (int i = start; i <= end; i++)
    {
        int n = i;
        int sum = 0;
        while (n > 0)
        {
            int temp = n % 10;
            sum = sum + pow(temp, 3);
            n = n / 10;
        }
        if (sum == i)
        {
            printf("%d ", i);
        }
    }
    return 0;
}