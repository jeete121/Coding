#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    str.replace(str.begin(), str.begin() + 1, "def");

    cout << str << "\n";

    return 0;
}
/*
Replace range of characters with C string.

Parameters:
__i1 – Iterator referencing start of range to replace.
__i2 – Iterator referencing end of range to replace.
__s – C string value to insert.

Returns:
Reference to this string.
*/