#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";
    string str2 = "aa";

    cout << str.compare(str2) << "\n";
    

    return 0;
}
/*
Compare to a string.

Parameters:
__str – String to compare against.

Returns:
Integer < 0, 0, or > 0. Returns an integer < 0 if this string is 
ordered before * __str, 0 if their values are equivalent, or > 0 
if this string is ordered after __str. Determines the effective 
length rlen of the strings to compare as the smallest of size() 
and str.size(). The function then compares the two strings by 
calling traits::compare(data(), str.data(),rlen). If the result
 of the comparison is nonzero returns it, otherwise the shorter 
 one is ordered first.
*/