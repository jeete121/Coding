#include <bits/stdc++.h>
using namespace std;

void heapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n)
    {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;

        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}
void heapSort(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        heapify(a, 1, i - 1);
    }
}
void buildHeap(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        heapify(a, i, n);
}
int main()
{
    int n = 5;

    int a[n] = {4, 5, 3, 7, 2};

    int arr[n + 1];
    for (int i = 0; i < n; i++)
        arr[i + 1] = a[i];
    buildHeap(arr, n);
    heapSort(arr, n);

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i];
        if (i != n)
            cout << ", ";
    }
    return 0;
}