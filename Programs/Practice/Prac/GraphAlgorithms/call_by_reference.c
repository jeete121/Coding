#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int num1 = 10, num2 = 20;

    printf("Numbers befor swapping are num1 = %d, num2 = %d\n", num1, num2);
    //call by reference to swap two
    //numbers
    swap(&num1, &num2);
    printf("Numbers after swapping are num1 = %d , num2 = %d ", num1, num2);
    return 0;
}