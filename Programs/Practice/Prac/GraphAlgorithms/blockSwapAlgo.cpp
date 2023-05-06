#include <bits/stdc++.h>
using namespace std;

void swapSubArray(int arr[], int start, int end, int k)
{
    for (int i = 0; i < k; i++)
    {

        //swap two varibales
        swap(arr[start + i], arr[end + i]);
    }
}
void blockSwapAlgo(int arr[], int k, int n)
{
    //base case if 0 elments or
    //elements are same as size of array
    if (k == 0 || k == n)
        return;
    if (k == (n - k))
    {
        swapSubArray(arr, 0, (n - k), k);
        return;
    }
    else if (k < (n - k))
    {
        swapSubArray(arr, 0, (n - k), k);
        blockSwapAlgo(arr, k, (n - k));
    }
    else
    {
        swapSubArray(arr, 0, k, (n - k));
        blockSwapAlgo((arr + n - k), (2 * k - n), k);
    }
}

int main()

{
    int arr[] = {4, 8, 6, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    blockSwapAlgo(arr, k, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}