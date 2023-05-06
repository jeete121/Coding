#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle *tr, int n)
{
    // Sort an array a of the length n
    int *p = malloc(n * sizeof(int));

    //find the area of each triangle
    for (int i = 0; i < n; i++)
    {
        float a = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        p[i] = (a * (a - tr[i].a) * (a - tr[i].b) * (a - tr[i].c));
    }

    //sort the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                temp = tr[j].a;
                tr[j].a = tr[j + 1].a;
                tr[j + 1].a = temp;
                temp = tr[j].b;
                tr[j].b = tr[j + 1].b;
                tr[j + 1].b = temp;
                temp = tr[j].c;
                tr[j].c = tr[j + 1].c;
                tr[j + 1].c = temp;
            }
        }
    }
}

int main()
{
    int n = 3;
    triangle *tr = malloc(n * sizeof(triangle));

    tr[0].a = 7, tr[0].b = 24, tr[0].c = 25;
    tr[1].a = 5, tr[1].b = 12, tr[1].c = 13;
    tr[2].a = 3, tr[2].b = 4, tr[2].c = 5;

    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}