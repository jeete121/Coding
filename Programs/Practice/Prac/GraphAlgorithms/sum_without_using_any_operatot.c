#include <stdio.h>

int addNumbers(int x, int y)
{
    return printf("%*c%*c", x, ' ', y, ' ');
}

int main()
{
    int num1 = 5, num2 = 10;

    int sum = addNumbers(num1, num2);

    printf("Sum is %d ", sum);
    return 0;
}