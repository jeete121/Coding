#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[1000];
    char str1[] = "Hello World";
    memccpy(str, str1, 0, sizeof(str1));

    cout << str << "\n";

    return 0;
}
/*
void *memccpy(void *_Dst, const void *_Src, int _Val, size_t _Size)

File: string.h
*/