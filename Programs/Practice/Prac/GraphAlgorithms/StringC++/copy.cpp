#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";
    char str2[] = "def";

    cout << str.copy(str2, 4, 0) << "\n";

    

    return 0;
}
/*
Copy substring into C string.

Parameters:
__s – C string to copy value into.
__n – Number of characters to copy.
__pos – Index of first character to copy.

Returns:
Number of characters actually copied

File: basic_string.tcc
*/