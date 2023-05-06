#include <stdio.h>
int main()
{
    int m, n;
    printf("Enter starting number : ");
    scanf("%d", &m);
    printf("Enter ending number : ");
    scanf("%d", &n);
    int i = m;
    int even = 0, odd = 0;
    int evenNum[n - m], oddNum[n - m];
    int l = 0, r = 0;
    while (i <= n)
    {
        if (i % 2 == 0)
        {
            even += i;
            evenNum[l] = i;
            l++;
            i++;
        }
        else
        {
            odd += i;
            oddNum[r] = i;
            r++;
            i++;
        }
    }
    printf("Even numbers are :\n");
    for (i = 0; i < l; i++)
    {
        printf("%d ", evenNum[i]);
    }
    printf("\n");
    printf("Odd numbers are :\n");
    for (i = 0; i < r; i++)
    {
        printf("%d ", oddNum[i]);
    }
    printf("\n");
    printf("Sum of even numbers from %d to %d is %d\n", m, n, even);
    printf("Sum of odd numbers from %d to %d is %d\n", m, n, odd);
    return 0;
}