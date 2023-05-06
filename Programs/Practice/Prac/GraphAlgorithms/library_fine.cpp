#include <bits/stdc++.h>
using namespace std;

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2)
{
    int fine;
    if (y1 < y2)
        return 0;
    if ((y1 - y2) == 0)
    {
        if (m1 < m2)
            return 0;
        if ((m1 - m2) == 0)
        {
            if (d1 - d2 <= 0)
                fine = 0;
            else
                fine = 15 * (d1 - d2);
        }
        else
        {
            fine = 500 * (m1 - m2);
        }
    }
    else
        fine = 10000;
    return fine;
}

int main()
{

    int d1 = 9, m1 = 6,y1 = 2015;
    int d2 = 6, m2 = 6, y2 = 2015;
    cout << libraryFine(d1, m1, y1, d2, m2, y2);
    return 0;
}
