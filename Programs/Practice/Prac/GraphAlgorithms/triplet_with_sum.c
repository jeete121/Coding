#include <stdio.h>

int main()
{
    int arr[] = {2, 3, 4, 1, 3, 5};
    int target = 9;

    int n = sizeof(arr) / sizeof(arr[0]);
    int flag = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n && flag == 0; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    printf("Triplet with %d as sum is ", target);
                    printf(" %d ,%d ,%d\n", arr[i], arr[j], arr[k]);
                    flag = 1;
                    break;
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("No triplet is found\n");
    }
    return 0;
}