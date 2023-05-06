#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t... I>
array<T, sizeof...(I)> make_array(T const &value, index_sequence<I...>)
{
    return array<T, sizeof...(I)>{(I, value)...};
}

template <int N, typename T>
array<T, N> make_array(T const &value)
{
    //use of make_index_sequence
    return make_array(value, make_index_sequence<N>());
}

int main()
{

    auto array = make_array<5>(string("5"));
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
}
/*
template<std::size_t _Num> using std::make_index_sequence<_Num> =
std::make_integer_sequence<std::size_t, _Num>

File: utility
*/
