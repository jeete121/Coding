#include <stdio.h>
int main()
{
    float x, y;

    printf("Enter x coordinate of the point : ");
    scanf("%f", &x);

    printf("Enter y coordinate of the point : ");
    scanf("%f", &y);

    if (x == 0 && y == 0)
    {
        printf("Origin\n");
    }
    else if (x == 0 && y != 0)
    {
        printf("On the Y - axis\n");
    }
    else if (y == 0 && x != 0)
    {
        printf("On the X - axis\n");
    }
    else if (x > 0 && y > 0)
    {
        printf("First Quadrant\n");
    }
    else if (x < 0 && y > 0)
    {
        printf("Second Quadrant\n");
    }
    else if (x < 0 && y < 0)
    {
        printf("Third Quadrant\n");
    }
    else if (x > 0 && y < 0)
    {
        printf("Fourth  Quadrant\n");
    }
}