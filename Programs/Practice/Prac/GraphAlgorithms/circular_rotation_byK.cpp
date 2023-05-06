#include <bits/stdc++.h>
using namespace std;

void circularRotatebyK(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n;
    int temp[k];
    for (int i = 0; i < n-k; i++)
        temp[i] = arr[i];
    int l = 0;
    for (int i = n-k; i < n; i++)
        arr[l++] = arr[i];

    for (int i = 0; i < n-k; i++)
        arr[l++] = temp[i];
}
int main()

{
    vector<int> arr = {3,4,2,1,9};
    int k = 2;

    circularRotatebyK(arr, k);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}