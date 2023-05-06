#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int oddCount = 0;
    int evenCount = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }
    if (evenCount > 0 && oddCount > 0)
    {
        printf("Both\n");
    }
    else if (evenCount > 0)
    {
        printf("Even\n");
    }
    else
    {
        printf("Odd\n");
    }
    return 0;
}