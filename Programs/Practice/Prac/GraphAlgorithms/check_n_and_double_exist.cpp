#include <bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (i != j)
            {
                if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i])
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {10, 2, 5, 3};
    if (checkIfExist(arr))
        cout << "true";
    else
        cout << "false";
    return 0;
}