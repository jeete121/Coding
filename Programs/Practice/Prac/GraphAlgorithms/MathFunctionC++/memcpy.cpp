#include <bits/stdc++.h>
using namespace std;

int main()
{
    char destination[1000];
    char source[] = "Hello World";

    //copy contents of the source into destination
    memcpy(destination, source, sizeof(source));

    cout << destination << "\n";

    return 0;
}
/*
void *memcpy(void *__restrict__ _Dst, const void *__restrict__ _Src, 
size_t _Size)

File: string.h
*/