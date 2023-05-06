#include <bits/stdc++.h>
using namespace std;
#define m 10000

int averageStudent(int n, vector<int> &arr)
{
    int y1 = 0, y2 = 0, y3 = 0, y4 = 0;
    int b[m + 1];
    for (int i = 0; i <= m; i++)
        b[i] = 1;
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j * i <= m; j++)
            b[i * j]++;
    }
    for (int i = 0; i < n; i++)
    {
        int x = b[arr[i]];
        if (x == 1)
            y1++;
        else if (x == 2)
            y2++;
        else if (x == 3)
            y3++;
        else if (x == 4)
            y4++;
    }
    return y2 + y3 - y1 - y4;
}
int main()
{
    int n = 3;
    vector<int>arr = {2, 3, 6};

    cout << averageStudent(n, arr);
    return 0;
}