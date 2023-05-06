#include <bits/stdc++.h>
using namespace std;
int main()
{

    try
    {
        int size = -10;
        int *arr = new int[size];
    }
    catch (std::bad_array_new_length &e)
    {
        std::cerr << "bad_array_new_length occured " << e.what() << '\n';
    }

    return 0;
}
/*
Type of the exceptions thrown by array new-expressions in any of 
these cases:
If the array size is less than zero.
If the array size is greater than an implementation-defined limit.
If the number of elements in the initializer list exceeds the number 
of elements to initialize.

This class is derived from bad_alloc (which is itself derived from
 exception). See the exception class for the member definitions of 
 standard exceptions.

Its member what returns a null-terminated character sequence 
identifying 
the exception.

class std::bad_array_new_length

File: new
*/