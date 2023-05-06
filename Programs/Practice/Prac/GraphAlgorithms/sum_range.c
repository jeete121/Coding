#include <stdio.h>
int main()
{
    int start, end;
    
    printf("Enter starting number : ");
    scanf("%d", &start);

    printf("Enter ending number : ");
    scanf("%d", &end);

    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum = sum + i;
    }

    printf("Sum of elements in range %d to %d is %d", start, end, sum);
    return 0;
}