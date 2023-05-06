#include <stdio.h>

int areaOfRectangle(int length, int width)
{
    int area = length * width;
    return area;
}
int main()
{
    int length, width;
    printf("Enter length and width of rectangle : ");
    scanf("%d%d", &length, &width);
    int area = areaOfRectangle(length, width);
    printf("Area of rectangle %d", area);
    return 0;
}