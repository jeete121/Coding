#include <bits/stdc++.h>
using namespace std;

string fun(char *ch, size_t len)
{
    mbstate_t mbs;

        mbrlen(NULL, 0, &mbs);
    size_t length;
    string str = "";
    while (len > 0)
    {
        length = mbrlen(ch, len, &mbs);

        //if the length is zero or length is greater than
        //remainig len of the string break out of loop
        if (length == 0 || length > len)
            break;

        // appends all the characters into res
        for (int i = 0; i < length; i++)
            str += (*ch++);

        //decrease the orginal len by length
        len -= length;
    }

    return str;
}
int main()
{
    char ch[] = "Hello World!";

    cout << fun(ch, sizeof(ch)) << "\n";
    return 0;
}
/*
size_t mbrlen(const char *__restrict__ _Ch, 
size_t _SizeInBytes, mbstate_t *__restrict__ _State)

File: wchar.h
*/