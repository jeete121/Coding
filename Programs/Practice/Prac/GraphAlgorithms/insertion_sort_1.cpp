#include <bits/stdc++.h>
using namespace std;

void insertionSort1(int n, vector<int> arr)
{
    int temp = arr[n - 1];
    int i = n - 2;
    while (i >= 0)
    {
        if (temp < arr[i])
        {
            arr[i + 1] = arr[i];
            for (int j = 0; j < n; j++)
                cout << arr[j] << " ";
            cout << "\n";
            i = i - 1;
        }
        else
        {
            arr[i + 1] = temp;
            break;
        }
    }
    if (i < 0)
        arr[i + 1] = temp;
    for (int j = 0; j < n; j++)
        cout << arr[j] << " ";
}
int main()
{
    int n = 5;
    vector<int> arr = {2, 4, 6, 8, 3};

    insertionSort1(n, arr);
    return 0;
}
