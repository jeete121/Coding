#include <bits/stdc++.h>
using namespace std;

int main()
{
    tuple<int, int, int> t;
    t = make_tuple(1, 2, 3);

    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
     
    return 0;
}
/*
template<class... _Elements> constexpr std::tuple<std::
__decay_and_strip<_Elements>::__type...> 
std::make_tuple(_Elements &&...__args)

NB: DR 705.

File: tuple
*/