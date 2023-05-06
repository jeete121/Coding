#include <bits/stdc++.h>
using namespace std;

int equalizeArray(vector<int> arr)
{
    int f[101] = {0};

    //find the frequency of each elements
    for (int i = 0; i < arr.size(); i++)
    {
        f[arr[i]]++;
    }

    //sort the frequency array
    sort(f, f + 101);
    int sum = 0;
    for (int i = 1; i < 100; i++)
    {
        sum += f[i];
    }
    return sum;
}

int main()
{
    int n = 5;
    vector<int> arr = {3, 3, 2, 1, 3};
    cout << equalizeArray(arr);
    return 0;
}
