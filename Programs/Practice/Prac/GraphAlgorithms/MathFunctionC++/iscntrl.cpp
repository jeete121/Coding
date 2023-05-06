#include <bits/stdc++.h>
using namespace std;

int main()
{

    char ch[] = "Hello world \n Ram";

    for (int i = 0; !iscntrl(ch[i]); i++)
    {
        cout << ch[i];
    }

    return 0;
}
/*
int iscntrl(int _C)

+1 overload

File: ctype.h
*/