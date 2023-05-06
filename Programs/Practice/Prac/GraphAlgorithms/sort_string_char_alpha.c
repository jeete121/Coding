#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    char arr[n + 1];

    printf("Enter the string characters: ");
    for (int i = 0; i < n + 1; i++)
        scanf("%c", &arr[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("String after sort is: ");
    for (int i = 0; i < n + 1; i++)
        printf("%c", arr[i]);
    return 0;
}