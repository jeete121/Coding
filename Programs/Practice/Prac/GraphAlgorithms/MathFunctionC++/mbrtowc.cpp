#include <bits/stdc++.h>
using namespace std;

int main()
{

    wchar_t dest;
    mbstate_t mbs;
    const char *str = "Hello World!";
    int max = sizeof(str);
    mbrlen(NULL, 0, &mbs);

    while (max > 0)
    {
        size_t length = mbrtowc(&dest, str, max, &mbs);
        if ((length == 0) || (length > max))
            break;
        wprintf(L"%lc", dest);
        str += length;
        max -= length;
    }

    return 0;
}
/*
size_t mbrtowc(wchar_t *__restrict__ _DstCh, 
const char *__restrict__ _SrcCh, size_t _SizeInBytes, 
mbstate_t *__restrict__ _State)


Convert multibyte sequence to wide character
The multibyte character pointed by pmb is converted to a value of 
type wchar_t and stored at the location pointed by pwc.
 The function returns the length in bytes of the multibyte character.

The function uses (and updates) the shift state described by ps. 
If ps is a null pointer, the function uses its own internal shift 
state, which is altered as necessary only by calls to this function.
File: wchar.h
*/