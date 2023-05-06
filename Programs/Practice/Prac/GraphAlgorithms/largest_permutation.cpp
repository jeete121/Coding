#include <bits/stdc++.h>
using namespace std;

vector<int> largestPermutation(int k, vector<int> arr)
{
    int n = arr.size();
    int temp, j;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != n - i && k != 0)
        {
            j = i + 1;
            while (arr[j] != n - i)
            {
                j++;
            }
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            k--;
        }
    }
    return arr;
}
int main()
{

    int k = 1;
    vector<int> arr = {4, 2, 3, 5, 1};

    vector<int> result = largestPermutation(k, arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }

    return 0;
}
