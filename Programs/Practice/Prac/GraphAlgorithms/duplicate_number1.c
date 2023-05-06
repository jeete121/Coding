#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array numbers: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int duplicate[n];
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n;)
        {
            if (arr[j] == arr[i])
            {
                duplicate[l] = arr[i];
                l++;
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }
    printf("Array after delete of duplicate elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Duplicate elements are : ");
    for (int i = 0; i < l; i++)
        printf("%d ", duplicate[i]);
    return 0;
}