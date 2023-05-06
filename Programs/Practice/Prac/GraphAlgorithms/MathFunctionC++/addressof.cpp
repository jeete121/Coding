#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 4, 5};

    cout << addressof(arr) << "\n";

    return 0;
}
/*
Returns the actual address of the object or function referenced by r, 
even in the presence of an overloaded operator&.

Parameters:
__r – Reference to an object or function.

Returns:
The actual address.

File: move.h
*/