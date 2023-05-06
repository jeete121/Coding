#include <bits/stdc++.h>
using namespace std;

int main()
{
    try
    {
        char ch = 'a';
    }
    catch (const std::bad_exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
/*
class std::bad_exception

If an %exception is thrown which is not listed in a function's
%exception specification, one of these may be thrown.

File: exception
*/
