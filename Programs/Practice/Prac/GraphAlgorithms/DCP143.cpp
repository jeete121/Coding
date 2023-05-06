#include <bits/stdc++.h>
using namespace std;

vector<int> partition(vector<int> &arr, int pivot)
{
    int i, temp, top = arr.size() - 1, mid = 0;
    bool step = true;
    for (i = 0; i <= top - mid; i++)
    {
        if (mid && step)
        {
            arr[i] = arr[i + mid];
        }
        step = true;
        if (arr[i] > pivot)
        {
            if (arr[top] == pivot)
            {
                arr[top--] = arr[i];
                arr[i] = arr[i + (++mid)];
            }
            else
            {
                temp = arr[i];
                arr[i] = arr[top];
                arr[top--] = temp;
                step = false;
            }
            i--;
        }
        else if (arr[i] == pivot)
        {
            mid++;
            i--;
        }
    }
    while (mid--)
    {
        arr[i++] = pivot;
    }
    return arr;
}
int main()
{
    int x = 10;
    vector<int> arr = {9, 12, 3, 5, 14, 10, 10};

    vector<int> res = partition(arr, x);

    cout << "[";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}