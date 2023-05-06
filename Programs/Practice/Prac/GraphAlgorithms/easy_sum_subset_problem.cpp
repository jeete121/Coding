#include <bits/stdc++.h>
using namespace std;

void sumSubset(int n, int arr[], int m, int brr[])
{
    set<int> a, c;

    for (int i = 0; i < n; i++)
    {

        a.insert(arr[i]);
    }
    for (int i = 0; i < m; i++)
    {

        c.insert(brr[i]);
    }
    auto it1 = a.end();
    auto it2 = c.end();
    it1--;
    it2--;
    auto it3 = a.begin();
    auto it4 = c.begin();
    int min1 = *it4 - *it3;
    int max1 = *it2 - *it1;

    vector<int> v;
    for (int i = min1; i <= max1; i++)
    {
        int flag = 0;
        for (auto it = a.begin(); it != a.end(); it++)
        {
            int x = i + *it;
            if (c.find(x) == c.end())
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            v.push_back(i);
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}
int main()
{
    int n = 2;

    int arr[] = {1, 2};
    int m = 3;

    int brr[] = {3, 4, 5};

    sumSubset(n, arr, m, brr);

    return 0;
}