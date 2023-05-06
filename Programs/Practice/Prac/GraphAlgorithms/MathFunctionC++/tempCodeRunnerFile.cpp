#include <bits/stdc++.h>
using namespace std;

int main()
{
    char _Buf1[] = "Hello";
    char _Buf2[] = "World";

    int val = memcmp(_Buf1, _Buf2, sizeof(_Buf1));

    cout << val << "\n";

    return 0;
}