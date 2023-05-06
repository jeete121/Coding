#include <stdio.h>
int main()
{
    char ch;
    int num;
    float floatNum;
    double doubleNum;
    long longNum;
    printf("Enter a charcter : ");
    ch = getchar();
    getchar();
    printf("Enter a integer number : ");
    scanf("%d", &num);

    printf("Enter a floating point number : ");
    scanf("%f", &floatNum);

    printf("Enter a double number : ");
    scanf("%lf", &doubleNum);

    printf("Enter a long number : ");
    scanf("%ld", &longNum);

    printf("\n\n");
    printf("Character is '%c' \n", ch);
    printf("Number is %d\n", num);

    printf("Floating point number is %f\n", floatNum);
    printf("Double number is %lf\n", doubleNum);
    printf("Long value is %ld\n", longNum);

    return 0;
}