#include <bits/stdc++.h>
using namespace std;

int binpower(int a, int b)
{
    int res = 1;
    for (int i = 1; i <= b; i++)
    {
        res = res * a;
    }
    return res;
}

int main()
{
    int a = 2, n = 10;

    cout << binpower(a, n);

    return 0;
}

//Time Complexity : O(n)