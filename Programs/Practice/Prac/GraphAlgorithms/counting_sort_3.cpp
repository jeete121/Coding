#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    vector<int> arr = {4, 3, 0, 1, 5, 1, 2, 4, 2, 4};
    vector<string> str = {"that", "be", "to", "be",
                          "question", "or", "not",
                          "is", "to", "the"};
    int f[100] = {0};
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        f[x]++;
    }
    for (int i = 1; i < 100; i++)
    {
        f[i] = f[i] + f[i - 1];
    }
    for (int i = 0; i < 100; i++)
        cout << f[i] << " ";
    return 0;
}
