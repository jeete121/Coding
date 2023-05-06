#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr(10);
    iota(arr.begin(), arr.end(), 10);
    

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}
/*
Create a range of sequentially increasing values. For each 
element in the range [first,last) assigns value and increments
 value as if by ++value.

Parameters:
__first – Start of range.
__last – End of range.
__value – Starting value.

Returns:
Nothing.

File: stl_numeric.h
*/