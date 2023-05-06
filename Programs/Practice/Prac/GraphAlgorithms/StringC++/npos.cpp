#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    if (str.find("d") == string::npos)
        cout << "Not present";
    else
        cout << "Present\n";

    return 0;
}
/*
static const std::size_t std::__cxx11::string::npos = 18446744073709551615ULL
Value returned by various member functions when they fail.
*/