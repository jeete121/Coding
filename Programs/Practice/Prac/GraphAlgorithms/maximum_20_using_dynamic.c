#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num = 20;
    int *dataMemory;

    // memory allocation
    dataMemory = (int *)calloc(num, sizeof(int));
    if (dataMemory == NULL)
    {
        printf("Error!!! memory not allocated.");
        exit(0);
    }
    printf("Enter 20 numbers:\n");
    for (int i = 0; i < num; ++i)
    {
        scanf("%d", dataMemory + i);
    }

    // Finding the largest number
    for (int i = 1; i < num; ++i)
    {
        if (*dataMemory < *(dataMemory + i))
        {
            *dataMemory = *(dataMemory + i);
        }
    }
    printf("Largest number is %d", *dataMemory);
    return 0;
}
