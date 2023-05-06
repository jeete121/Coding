#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> arr, int l, int h)
{
    int aux[h - l + 1];
    int mid = (l + h) / 2;
    int i = l, j = mid + 1, k = 0, count = 0;

    while (i <= mid && j <= h)
    {
        if (arr[j] < arr[i])
        {
            aux[k] = arr[j];
            j++;
            count += mid - i + 1;
        }
        else
        {
            aux[k] = arr[i];
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        aux[k] = arr[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        aux[k] = arr[j];
        j++;
        k++;
    }

    k = 0;
    for (int x = l; x <= h; x++)
    {
        arr[x] = aux[k];
        k++;
    }

    return count;
}

long long mergeSort(vector<int> arr, int lo, int hi)
{
    if (lo >= hi)
        return 0;

    int mid = (lo + hi) / 2, count = 0;

    count += mergeSort(arr, lo, mid);
    count += mergeSort(arr, mid + 1, hi);
    count += merge(arr, lo, hi);

    return count;
}

long long countInversions(vector<int> a)
{

    return mergeSort(a, 0, a.size() - 1);
}

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};

    cout << countInversions(arr);

    return 0;
}