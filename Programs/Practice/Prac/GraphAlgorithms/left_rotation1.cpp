#include <bits/stdc++.h>
using namespace std;

void leftRotate(vector<int> &arr)
{
    int temp = arr[0];
    int i = 0;
    for (i = 0; i < arr.size() - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[i] = temp;
}
int main()
{
    vector<int> arr = {3, 2, 1, 5, 4};

    leftRotate(arr);
    cout << "Left Rotated Array is : ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}