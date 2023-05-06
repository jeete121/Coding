#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int sum = 0;

    cout << accumulate(arr.begin(), arr.end(), sum) << "\n";

    return 0;
}
/*
Accumulate values in a range. Accumulates the values in the 
range [first,last) using operator+(). The initial value is init. 
The values are processed in order.

File: stl_numeric.h
*/