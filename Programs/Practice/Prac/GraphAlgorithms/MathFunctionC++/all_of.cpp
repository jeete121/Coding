#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 15, 17};
    if (all_of(arr.begin(), arr.end(), [](int i)
               { return i & 1; }))
        cout << "All odd\n";
    else
        cout << "All are not odd\n";


    return 0;
}
/*
Checks that a predicate is true for all the elements of a sequence.

Parameters:
__first – An input iterator.
__last – An input iterator.
__pred – A predicate.

Returns:
True if the check is true, false otherwise. Returns true if __pred is 
true for each element in the range [__first,__last), and false otherwise.
*/