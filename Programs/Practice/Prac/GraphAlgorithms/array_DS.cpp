#include <bits/stdc++.h>
using namespace std;

vector<int> reverseArray(vector<int> a)
{

    vector<int> res;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        res.push_back(a[i]);
    }
    return res;
}
int main()
{
    int n = 4;
    vector<int> arr = {1, 4, 3, 2};

    vector<int> rev = reverseArray(arr);
    for (int i = 0; i < rev.size(); i++)
    {
        cout << rev[i] << " ";
    }
    return 0;
}
