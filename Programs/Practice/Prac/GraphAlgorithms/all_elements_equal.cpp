#include <bits/stdc++.h>
using namespace std;

bool isEqualElements(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        while (arr[i] % 2 == 0)
            arr[i] = arr[i] / 2;
        while (arr[i] % 3 == 0)
            arr[i] = arr[i] / 3;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != arr[0])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> arr = {100, 50, 75};

    if (isEqualElements(arr))
        cout << "true";
    else
        cout << "false";
}