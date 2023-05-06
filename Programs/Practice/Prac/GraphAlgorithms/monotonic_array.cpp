#include <bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int> &A)
{
    int n = A.size();
    int i = 1;
    while (i < n && A[i] >= A[i - 1])
    {
        i++;
    }
    if (i == n)
        return true;
    i = 1;
    while (i < n && A[i] <= A[i - 1])
    {
        i++;
    }
    if (i == n)
        return true;
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};

    if (isMonotonic(arr))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}