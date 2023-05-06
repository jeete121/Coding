#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    str.reserve(10);

    cout << str.size() << "\n";

    return 0;
}
/*
Attempt to preallocate enough memory for specified number of characters.

Parameters:
__res_arg – Number of characters required.

File: basic_string.tcc
*/