#include <bits/stdc++.h>
using namespace std;

int bitwiseComplement(int N)
{
    if (N == 0)
        return 1;
    vector<int> arr;
    while (N > 0)
    {
        if (N % 2 == 0)
            arr.push_back(1);
        else
            arr.push_back(0);
        N = N / 2;
    }
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        res += arr[i] * pow(2, i);
    }
    return res;
}
int main()
{
    int n = 5;

    cout << bitwiseComplement(n);
    return 0;
}