#include <bits/stdc++.h>
using namespace std;

vector<int> missingNumbers(vector<int> arr, vector<int> brr)
{
    int f[10001] = {0};
    for (int i = 0; i < brr.size(); i++)
        f[brr[i]]++;
    for (int i = 0; i < arr.size(); i++)
        f[arr[i]]--;
    vector<int> res;
    for (int i = 1; i < 10001; i++)
        if (f[i])
            res.push_back(i);
    return res;
}

int main()
{

    int n = 6;
    vector<int> arr = {7, 2, 5, 3, 5, 3};

    int m = 8;

    vector<int> brr = {7, 2, 5, 4, 6, 3, 5, 3};

    vector<int> result = missingNumbers(arr, brr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}
