#include <bits/stdc++.h>
using namespace std;

vector<int> icecreamParlor(int m, vector<int> arr)
{
    int n = arr.size();
    vector<int> res;
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == m)
            {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            }
    return res;
}

int main()
{

    int m = 4;

    int n = 5;

    vector<int> arr = {1, 4, 5, 3, 2};

    vector<int> result = icecreamParlor(m, arr);

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
