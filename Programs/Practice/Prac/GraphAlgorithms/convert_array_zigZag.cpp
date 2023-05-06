#include <bits/stdc++.h>
using namespace std;

void zigZagArray(vector<int> &arr)
{

    bool flag = true;
    for (int i = 0; i < arr.size() - 3; i++)
    {
        if (flag)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        else
        {
            if (arr[i] < arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }

        //change the flag value
        flag = !flag;
    }
}
int main()
{
    vector<int> arr = {4, 3, 7, 8, 6, 2, 1};

    zigZagArray(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
