#include <stdio.h>

void printRec(int n)
{
    if (n < 10)
    {
        printf("%d\n", n);
        return;
    }
    else
    {
        printRec(n / 10);
        printf("%d\n", n % 10);
    }
}
int main()
{
    int num;
    printf("Enter a five digit number : ");
    scanf("%d", &num);

    printRec(num);
    return 0;
}