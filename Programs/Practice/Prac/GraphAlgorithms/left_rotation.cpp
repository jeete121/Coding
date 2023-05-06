#include <bits/stdc++.h>
using namespace std;

vector<int> rotateLeft(int d, vector<int> arr)
{
    int n = arr.size();
    d = d % n;
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    int l = 0;
    for (int i = d; i < n; i++)
    {
        arr[l++] = arr[i];
    }
    for (int i = 0; i < d; i++)
    {
        arr[l++] = temp[i];
    }
    return arr;
}
int main()
{
    int n = 5, d = 4;

    vector<int> arr = {1, 2, 3, 4, 5};
    arr = rotateLeft(d, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
