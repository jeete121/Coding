// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     basic_filebuf<char> bf;
//     bf.close()
    
// }

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <memory.h>
#include <string.h>

#define IBUFSIZE 16

using namespace std;

void hexdump(const string& filename);

int main()
{
    
    wchar_t* wszHello = L"Hello World";
    wchar_t wBuffer[128];

    basic_filebuf<wchar_t> wOutFile;

    // Open a file, wcHello.txt, then write to it, then dump the
    // file's contents in hex
    wOutFile.open("wcHello.txt",
        ios_base::out | ios_base::trunc | ios_base::binary);
    if(!wOutFile.is_open())
    {
        cout << "Error Opening wcHello.txt\n";
        return -1;
    }
    wOutFile.sputn(wszHello, (streamsize)wcslen(wszHello));
    wOutFile.close();
    cout << "Hex Dump of wcHello.txt - note that output is ANSI chars:\n";
    hexdump(string("wcHello.txt"));

    // Open a file, wwHello.txt, then set the internal buffer of
    // the basic_filebuf object to be of type wchar_t, then write
    // to the file and dump the file's contents in hex
    wOutFile.open("wwHello.txt",
        ios_base::out | ios_base::trunc | ios_base::binary);
    if(!wOutFile.is_open())
    {
        cout << "Error Opening wwHello.txt\n";
        return -1;
    }
    wOutFile.pubsetbuf(wBuffer, (streamsize)128);
    wOutFile.sputn(wszHello, (streamsize)wcslen(wszHello));
    wOutFile.close();
    cout << "\nHex Dump of wwHello.txt - note that output is wchar_t chars:\n";
    hexdump(string("wwHello.txt"));

    return 0;
}

// dump contents of filename to stdout in hex
void hexdump(const string& filename)
{
    fstream ifile(filename.c_str(),
        ios_base::in | ios_base::binary);
    char *ibuff = new char[IBUFSIZE];
    char *obuff = new char[(IBUFSIZE*2)+1];
    int i;

    if(!ifile.is_open())
    {
        cout << "Cannot Open " << filename.c_str()
             << " for reading\n";
        return;
    }
    if(!ibuff || !obuff)
    {
        cout << "Cannot Allocate buffers\n";
        ifile.close();
        return;
    }

    while(!ifile.eof())
    {
        memset(obuff,0,(IBUFSIZE*2)+1);
        memset(ibuff,0,IBUFSIZE);
        ifile.read(ibuff,IBUFSIZE);

        // corner case where file is exactly a multiple of
        // 16 bytes in length
        if(ibuff[0] == 0 && ifile.eof())
            break;

        for(i = 0; i < IBUFSIZE; i++)
        {
            if(ibuff[i] >= ' ')
                obuff[i] = ibuff[i];
            else
                obuff[i] = '.';

            cout << setfill('0') << setw(2) << hex
                 << (int)ibuff[i] << ' ';
        }
        cout << "  " << obuff << endl;
    }
    ifile.close();
}
/*
template<class _CharT, class _Traits = std::char_traits<_CharT>> 
class std::basic_filebuf<_CharT, _Traits>

The actual work of input and output (for files).

Template Parameters:
_CharT – Type of character stream.
_Traits – Traits for character type, defaults to char_traits<_CharT>.
 This class associates both its input and output sequence with an external
  disk file, and maintains a joint file position for both sequences.
   Many of its semantics are described in terms of similar behavior 
   in the Standard C Library's FILE streams. Requirements on traits_type,
    specific to this class: - traits_type::pos_type must be 
    fpos<traits_type::state_type> - traits_type::off_type must be
     streamoff - traits_type::state_type must be Assignable and 
     DefaultConstructible, - traits_type::state_type() must be the initial
      state for codecvt.

Stream buffer to read from and write to files.

Constructed without association, these objects are associated to a file by calling member open. Once open, all input/output operations performed on the object are reflected in the associated file.

Objects of this class may internally maintain an intermediate input buffer and/or an intermediate output buffer, where individual characters are read or written by i/o operations. These buffers are synchronized with the contents of the file once filled up, when explicitly requested to do so (sync), or when the object is closed.


File: fstream
*/