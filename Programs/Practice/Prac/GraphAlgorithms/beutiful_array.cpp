#include <bits/stdc++.h>
using namespace std;

vector<int> beautifulArray(int N)
{
    if (N == 1)
    {
        return {1};
    }

    int first = N / 2, second = (N + 1) / 2;
    vector<int> left = beautifulArray(first);
    vector<int> right = beautifulArray(second);

    for (int i = 0; i < left.size(); ++i)
    {
        left[i] *= 2;
    }

    for (int i = 0; i < right.size(); ++i)
    {
        right[i] = right[i] * 2 - 1;
    }

    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int main()
{
    int n = 4;

    vector<int> arr = beautifulArray(n);

    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}