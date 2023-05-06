#include <bits/stdc++.h>
using namespace std;

vector<int> permutationEquation(vector<int> arr)
{

    int n = arr.size();
    int x = 1, i = 0;
    vector<int> res;
    int l = 0;
    while (x <= n)
    {
        if (arr[arr[arr[i] - 1] - 1] == x)
        {
            res.push_back(arr[i]);
            i = 0;
            x = x + 1;
        }
        else
        {
            i++;
        }
    }
    return res;
}
int main()
{
    vector<int> arr = {4, 3, 5, 1, 2};

    vector<int> res = permutationEquation(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}