#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 4, 12, 11};

    if (any_of(arr.begin(), arr.end(), [](int i)
               { return i & 1; }))
        cout << "Any element in the array is odd\n";

    else
        cout << "No element in the array is odd\n";
    
    return 0;
}
/*
Checks that a predicate is false for at least an element of a sequence.

Parameters:
__first – An input iterator.
__last – An input iterator.
__pred – A predicate.

Returns:
True if the check is true, false otherwise. Returns true if an element 
exists in the range * [__first,__last) such that __pred is true, and 
false otherwise.
*/