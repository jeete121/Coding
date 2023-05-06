#include <bits/stdc++.h>
using namespace std;

int jumpingOnClouds(vector<int> arr, int k)
{

    int i = 0, e = 100;
    int n = arr.size();
    while (true)
    {
        i = (i + k) % n;
        if (arr[i] == 1)
        {
            e = e - 1 - 2;
        }
        else
        {
            e = e - 1;
        }
        if (i == 0)
        {
            break;
        }
    }
    return e;
}

int main()
{
    int n = 8, k = 2;
    vector<int> arr = {0, 0, 1, 0, 0, 1, 1, 0};

    cout << jumpingOnClouds(arr, k);
    return 0;
}
