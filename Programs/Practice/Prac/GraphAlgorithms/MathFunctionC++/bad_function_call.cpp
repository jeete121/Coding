#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    std::function<int(int, int)> fun;
    try
    {
        cout << fun(10, 12);
    }
    catch (const std::bad_function_call &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
/*
Exception class thrown when class template function's operator() is
 called with an empty target.

Type thrown by empty function objects when their functional call is invoked.

Empty function objects are function objects with no target callable object.

This class is derived from exception. See the exception class for the member definitions of standard exceptions.


File: std_function.h
*/