#include <bits/stdc++.h>
using namespace std;

void weirdThings(int n, int arr[])
{
    vector<int> v1, v2, res;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];

        if (x & 1)
        {
            v2.push_back(x);
            sum2 += x;
        }
        else
        {
            v1.push_back(x);
            sum1 += x;
        }
    }
    sort(v1.begin(), v1.end());
    v1.push_back(sum1);
    sort(v2.begin(), v2.end());
    v2.push_back(sum2);
    for (int i = 0; i < v1.size(); i++)
        res.push_back(v1[i]);
    for (int i = 0; i < v2.size(); i++)
        res.push_back(v2[i]);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "\n";
}
int main()
{
    int n = 6;
    int arr[] = {2, 3, 10, 12, 15, 22};

    weirdThings(n, arr);

    return 0;
}