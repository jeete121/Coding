#include <bits/stdc++.h>
using namespace std;

int main()

{
    char arr[] = "abcdef";

    void *pt = arr;
    size_t space = sizeof(arr) - 1;

    while (align(alignof(int), sizeof(char), pt, space))
    {

        //cast the void pointer into
        // char
        char *temp = static_cast<char *>(pt);
        ++temp;
        space -= sizeof(char);
        pt = temp;
    }

    cout << arr << "\n";
    return 0;
}
/*
Fit aligned storage in buffer. [ptr.align] This function 
tries to fit __size bytes of storage with alignment __align
 into the buffer __ptr of size __space bytes. If such a buffer 
 fits then __ptr is changed to point to the first byte of the 
 aligned storage and __space is reduced by the bytes used for alignment.

Parameters:
__align – A fundamental or extended alignment value.
__size – Size of the aligned storage required.
__ptr – Pointer to a buffer of __space bytes.
__space – Size of the buffer pointed to by __ptr.

Returns:
the updated pointer if the aligned storage fits, otherwise nullptr.

File: memory
*/