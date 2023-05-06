#include <bits/stdc++.h>
using namespace std;

map<int, int> spcarr;
void SparseArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i])
            spcarr[i] = arr[i];
    }
}

void set1(int i, int val)
{
    spcarr[i] = val;
}

int get(int i)
{
    if (spcarr.find(i) != spcarr.end())
        return spcarr[i];
    return 0;
}

int main()
{
    vector<int> arr = {2, 1, 0, 0, 0, 4, 5, 3, 0, 0, 0, 2};
    SparseArray(arr, arr.size());
    cout << get(4) << " ";
    cout << get(3) << " ";
    set1(3, 12);
    cout << get(3) << " ";
    return 0;
}