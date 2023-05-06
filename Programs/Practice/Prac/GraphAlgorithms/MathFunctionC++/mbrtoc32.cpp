#include <bits/stdc++.h>
using namespace std;

int main()
{

    mbstate_t ps;
    char32_t pc32;
    char s[] = "ABCD";
    int length = mbrtoc32(&pc32, s, MB_CUR_MAX, &ps);

    if (length < 0)
    {
        cout << "Failed\n";
    }
    else
    {
        cout << length << "\n";
        cout << pc32 << "\n";
    }
    return 0;

    return 0;
}
/*
size_t mbrtoc32(char32_t *__restrict__ pc32, 
const char *__restrict__ s, size_t n, mbstate_t *__restrict__ ps)

File: uchar.h
*/