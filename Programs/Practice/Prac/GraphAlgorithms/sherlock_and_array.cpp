#include <bits/stdc++.h>
using namespace std;

string balancedSums(vector<int> arr)
{
    int n = arr.size();
    int *left = (int *)malloc(sizeof(int) * n);
    int *right = (int *)malloc(sizeof(int) * n);

    left[0] = 0;
    right[n - 1] = 0;
    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] + arr[i - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] + arr[i + 1];
    int i = 0;
    while (i < n)
    {
        if (left[i] == right[i])
            return "YES";
        else
            i++;
    }
    return "NO";
}

int main()
{

    int n = 4;
    vector<int> arr = {1, 2, 3, 3};

    string result = balancedSums(arr);
    cout << result << "\n";

    return 0;
}