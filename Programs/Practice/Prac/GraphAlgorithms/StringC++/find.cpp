#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abcdef";

    cout << str.find("bc", 0) << "\n";
    

    return 0;
}
/*
Find position of a C string.

Parameters:
__s – C string to locate.
__pos – Index of character to search from (default 0).

Returns:
Index of start of first occurrence. Starting from __pos, 
searches forward for the value of * __s within this string. 
If found, returns the index where it begins. If not found, 
returns npos.
*/