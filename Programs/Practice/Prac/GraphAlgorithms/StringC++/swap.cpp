#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1 = "abc";
    string str2 = "defg";

    cout << str1 << " " << str2 << "\n";
    str1.swap(str2);

    cout << str1 << " " << str2 << "\n";

    return 0;
}
/*

Swap contents with another string.

Parameters:
__s – String to swap with. Exchanges the contents of this string 
with that of __s in constant time.

File: basic_string.tcc
*/