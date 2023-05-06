#include <bits/stdc++.h>
using namespace std;

int main()
{

    try
    {
        char *arr = new char[100];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Error has occured " << e.what() << '\n';
    }

    return 0;
}
/*
Type of the exceptions thrown by the standard definitions of operator 
new and operator new[] when they fail to allocate the requested storage
space.

Exception possibly thrown by new.

File: new
*/