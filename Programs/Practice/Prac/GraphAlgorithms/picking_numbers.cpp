#include <bits/stdc++.h>
using namespace std;

int pickingNumbers(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int max1 = 1;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {

        int x = arr[i];
        int cnt = 1;
        while (abs(arr[i + 1] - x) <= 1 &&
               abs(arr[i] - x) <= 1 &&
               abs(arr[i + 1] - arr[i]) <= 1)
        {
            cnt++;
            i++;
        }
        max1 = max(cnt, max1);
    }
    return max1;
}
int main()
{
    int n = 6;

    vector<int> arr = {1, 2, 2, 3, 1, 2};

    cout << pickingNumbers(arr);
    return 0;
}
