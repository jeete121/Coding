#include <bits/stdc++.h>
using namespace std;

vector<int> allPrimes(int N)
{
    vector<int> arr(N + 1, 0);
    arr[0] = 0;
    arr[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        arr[i] = 1;
    }
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= N; j = j + i)
            {
                arr[j] = 0;
            }
        }
    }
    return arr;
}

vector<int> twoPrimeWithSumN(int N)
{
    vector<int> arr(N + 1);
    arr = allPrimes(N);
    for (int i = 2; i <= N; i++)
    {
        if (arr[i] && arr[N - i])
        {
            return {i, N - i};
        }
    }
    return {};
}
int main()
{
    int N = 20;
    vector<int> res = twoPrimeWithSumN(N);

    if (res.size() > 0)
    {
        cout << res[0] << " " << res[1] << "\n";
    }
    else
        cout << "No Solution\n";
    return 0;
}