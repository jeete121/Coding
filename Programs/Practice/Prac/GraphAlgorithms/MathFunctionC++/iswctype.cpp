#include <bits/stdc++.h>
using namespace std;

int main()
{
    wchar_t C = L'p';

    cout << iswctype(C, wctype("alpha")) << "\n";

    return 0;
}
/*
int iswctype(wint_t _C, wctype_t _Type)

File: ctype.h
*/