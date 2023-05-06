#include <bits/stdc++.h>
using namespace std;

struct S
{
    virtual void f();
};

int main()
{


    S *pointer = NULL;
    try
    {
        typeid(*pointer).name();
    }
    catch (const std::bad_typeid &e)
    {
        std::cerr << "Error has occured " << e.what() << '\n';
    }

    return 0;
}
/*
class std::bad_typeid
Thrown when a NULL pointer in a typeid expression is used.

Type of the exceptions thrown by typeid when applied on a pointer to
 a polymorphic
 type which has a null pointer value.

Its member what returns a null-terminated character sequence 
identifying the exception.
*/