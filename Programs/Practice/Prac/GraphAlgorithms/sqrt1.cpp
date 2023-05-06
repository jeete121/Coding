#include <bits/stdc++.h>
using namespace std;

int squareRoot(int N)
{
    if (N == 0 || N == 1)
        return N;
    int start = 1;
    int end = N;
    int squareRoot = 1;

    //apply binary search
    while (start <= end)
    {
        //calculate mid point
        int mid = (start + end) / 2;
        if ((mid * mid) == N)
            return mid;
        if ((mid * mid) < N)
        {
            start = mid + 1;
            squareRoot = mid;
        }
        else
            end = mid - 1;
    }
    return squareRoot;
}

int main()
{
    int n = 10;

    cout << squareRoot(n);

    return 0;
}