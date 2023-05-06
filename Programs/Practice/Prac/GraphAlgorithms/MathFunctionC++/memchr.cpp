#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[] = "Hello World";
    char ch = 'l';
    char *pt = (char *)memchr(str, ch, sizeof(str));

    if (pt != NULL)
        cout << ch << " found at position " << pt - str << "\n";
    else
        cout << ch << " not found in the string\n";

    return 0;
}
/*
void *memchr(const void *_Buf, int _Val, size_t _MaxCount)

+1 overload

File: string.h
*/