#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    make_shared(vec);
    

    return 0;
}
/*
template<class _Tp, class... _Args> std::shared_ptr<_Tp> 
std::make_shared(_Args &&...__args)

Create an object that is owned by a shared_ptr.

Parameters:
__args – Arguments for the _Tp object's constructor.

Returns:
A shared_ptr that owns the newly created object.

File: shared_ptr.h
*/