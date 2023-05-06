#include <bits/stdc++.h>
using namespace std;

void fun()
{
    cout << "Atexit\n";
}
int main()
{
    int x = atexit(fun);
    if (x == 0)
        cout << "Succesfull\n";
    else
        cout << "Not Succesfull\n";

    

    return 0;
}
/*

Registers the function pointed to by func to be called on normal program
termination (via std::exit() or returning from the main function)
The same function may be registered more than once.

If a function exits via an exception, std::terminate is called.

atexit is thread-safe: calling the function from several threads does not
 induce a data race.

The implementation is guaranteed to support the registration of at least 32
 functions. 
The exact limit is implementation-defined.

Parameters
func	-	pointer to a function to be called on normal program termination
Return value
​0​ if the registration succeeds, nonzero value otherwise.

int atexit(void (*)())

File: stdlib.h

*/