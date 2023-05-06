#include <bits/stdc++.h>
using namespace std;

void rightRotate(vector<int> &arr)
{
    int temp = arr[arr.size() - 1];
    int i = arr.size() - 1;
    for (i = arr.size() - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}
int main()
{
    vector<int> arr = {3, 2, 1, 5, 4};

    rightRotate(arr);
    cout << "Right Rotated Array is : ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}