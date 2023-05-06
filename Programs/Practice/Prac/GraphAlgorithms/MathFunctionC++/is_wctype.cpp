#include <bits/stdc++.h>
using namespace std;

int main()
{
    wchar_t str[] = L"hello world";
    wctype_t type = wctype("lower");

    for (int i = 0; iswctype(str[i], type); i++)
    {
        wchar_t c = str[i];
        cout << c;
    }
    return 0;
}
/*
int is_wctype(wint_t _C, wctype_t _Type)

File: ctype.h
*/