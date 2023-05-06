#include <bits/stdc++.h>
using namespace std;

int runningTime(vector<int> arr)
{

    int n = arr.size();
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > x)
        {
            arr[j] = arr[j - 1];
            j--;
            cnt++;
        }
        arr[j] = x;
    }
    return cnt;
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 1, 3, 1, 2};

    cout << runningTime(arr);
    return 0;
}
