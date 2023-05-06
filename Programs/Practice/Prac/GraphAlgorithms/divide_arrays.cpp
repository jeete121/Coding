#include <bits/stdc++.h>
using namespace std;

int divideArrays(vector<int> A, int N)
{
    int mexLeft[N + 2];
    int mexRight[N + 2];

    for (int i = 0; i < N + 2; i++)
    {
        mexLeft[i] = 0;
        mexRight[i] = 0;
    }

    vector<int> seen(100002);
    for (int i = 1; i <= N; i++)
    {
        // fill mexLeft
        seen[A[i]] = 1;
        mexLeft[i] = mexLeft[i - 1];
        while (seen[mexLeft[i]] == 1)
        {
            mexLeft[i] = mexLeft[i] + 1;
        }
    }

    seen.clear();
    for (int i = N; i >= 1; i--)
    {
        // fill mexRight
        seen[A[i]] = 1;
        mexRight[i] = mexRight[i + 1];
        while (seen[mexRight[i]] == 1)
        {
            mexRight[i] = mexRight[i] + 1;
        }
    }

    // search smallest index
    int k = 1;
    while (k != N && mexLeft[k] != mexRight[k + 1])
    {
        k++;
    }
    if (k == N)
        return -1;
    else
        return k;
}
int main()
{
    int N = 5;
    vector<int> A = {0, 0, 2, 2, 3, 0};

    cout << divideArrays(A, N) << "\n";

    return 0;
}
