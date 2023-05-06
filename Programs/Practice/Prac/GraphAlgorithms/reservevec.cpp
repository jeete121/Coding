#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec;

    vec.reserve(5);
    for (int i = 1; i <= 5; i++)
    {
        vec[i - 1] = i;
    }
    for (int i = 0; i < 5; i++)
        cout << vec[i] << " ";
    
    return 0;
}
/*
Attempt to preallocate enough memory for specified number of elements.

Parameters:
__n – Number of elements required.

File: vector.tcc
*/