#include <bits/stdc++.h>
using namespace std;

int main()
{
    char _Buf1[] = "Hello";
    char _Buf2[] = "Abc";

    int val = memcmp(_Buf1, _Buf2, sizeof(_Buf1));

    cout << val << "\n";

    return 0;
}

/*
int memcmp(const void *_Buf1, const void *_Buf2, size_t _Size)

File: string.h
*/