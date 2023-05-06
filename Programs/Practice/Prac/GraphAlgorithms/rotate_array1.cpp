#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int low, int high)
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
void rotateArrayLeftByK(vector<int> &arr, int k)
{

    //reverse last k elements
    reverseArray(arr, 0, k - 1);

    //reverse the firt n-k elements
    reverseArray(arr, k, arr.size() - 1);

    //reverse the whole array
    reverseArray(arr, 0, arr.size() - 1);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    int k = 2;

    k = k % arr.size();
    rotateArrayLeftByK(arr, k);
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}