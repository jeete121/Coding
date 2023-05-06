#include <stdio.h>
#include <math.h>
void update(int *a, int *b)
{
    int c, d;
    c = *a + *b;
    d = fabs(*a - *b);
    printf("%d\n%d", c, d);
}

int main()
{
    int a = 4, b = 5;
    int *pa = &a, *pb = &b;
    update(pa, pb);
    return 0;
}
