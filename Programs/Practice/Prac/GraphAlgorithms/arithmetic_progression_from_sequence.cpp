#include <bits/stdc++.h>
using namespace std;

bool canMakeArithmeticProgression(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int diff = arr[0] - arr[1];
    int flag = 0;
    int n = arr.size();
    for (int i = 2; i < n; i++)
    {
        if (arr[i - 1] - arr[i] != diff)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return true;
    return false;
}

int main()
{
    vector<int> arr = {3, 5, 1};
    if (canMakeArithmeticProgression(arr))
        cout << "true";
    else
        cout << "false";
    return 0;
}