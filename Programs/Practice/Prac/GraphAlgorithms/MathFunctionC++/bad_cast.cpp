#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    
    try
    {
        int value = 10;
    }
    catch (const std::bad_cast &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
/*
class std::bad_cast

Thrown during incorrect typecasting.

File: typeinfo
*/