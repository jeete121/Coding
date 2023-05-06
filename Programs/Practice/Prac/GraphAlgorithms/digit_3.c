#include <stdio.h>
int main()
{
    int num = 30;

    int threeCount[num + 1];
    for (int i = 0; i <= num; i++)
    {
        threeCount[i] = 0;
    }
    for (int i = 1; i <= num; i++)
    {
        int j = i;
        while (j > 0)
        {
            int temp = j % 10;
            if (temp == 3)
            {
                threeCount[i]++;
            }
            j = j / 10;
        }
    }
    printf("Count of three in each number is\n");
    for (int i = 0; i <= num; i++)
    {
        printf("%d ", threeCount[i]);
    }

    return 0;
}
