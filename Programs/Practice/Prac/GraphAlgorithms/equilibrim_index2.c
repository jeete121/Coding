#include <stdio.h>
int main()
{
    int arr[] = {3, 2, 4, 5, 6, 8, 3, 2, 1};

    //find the length of array
    int n = sizeof(arr) / sizeof(arr[0]);

    int sumRem = 0;
    for (int i = 0; i < n; i++)
    {
        sumRem = sumRem + arr[i];
    }
    int flag = 0;
    int leftSum = 0;
    for (int i = 0; i < n; i++)
    {

        //update remaining sum
        sumRem = sumRem - arr[i];

        //if leftSum is same as remaining sum
        if (leftSum == sumRem)
        {
            printf("Equilibrium index is %d", i);
            flag = 1;
            break;
        }

        //update leftSum
        leftSum = leftSum + arr[i];
    }
    if (flag == 0)
    {
        printf("No Equilibrium index\n");
    }
    return 0;
}