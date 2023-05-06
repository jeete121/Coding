#include <bits/stdc++.h>
using namespace std;

int main()
{

    mbstate_t ps;
    char16_t pc16;
    char s[] = "ABCD";
    int length = mbrtoc16(&pc16, s, MB_CUR_MAX, &ps);

    if (length < 0)
    {
        cout << "Error\n";
    }
    else
    {
        cout << length << "\n";
    }
    return 0;
}
/*
size_t mbrtoc16(char16_t *__restrict__ pc16, 
const char *__restrict__ s, size_t n, mbstate_t *__restrict__ ps)

File: uchar.h
*/