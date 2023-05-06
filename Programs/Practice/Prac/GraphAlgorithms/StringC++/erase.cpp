#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abcdef";

    str.erase(1, 3);

    cout << str << "\n";
    
    return 0;
}
/*
Remove characters.

Parameters:
__pos – Index of first character to remove (default 0).
__n – Number of characters to remove (default remainder).

Returns:
Reference to this string.
*/