#include <bits/stdc++.h>
using namespace std;

void insertionSort2(int n, vector<int> arr)
{
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > x)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = x;
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << "\n";
    }
}
int main()
{
    int n = 6;
    vector<int> arr = {1, 4, 3, 5, 6, 2};
    insertionSort2(n, arr);
    return 0;
}
