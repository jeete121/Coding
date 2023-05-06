#include <bits/stdc++.h>
using namespace std;

void dnaPride(int n, string s)
{

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
        {
            flag = 1;
            break;
        }
        else if (s[i] == 'A')
            s[i] = 'T';
        else if (s[i] == 'T')
            s[i] = 'A';
        else if (s[i] == 'G')
            s[i] = 'C';
        else if (s[i] == 'C')
            s[i] = 'G';
    }
    if (flag)
        cout << "Error RNA nucleobases found!\n";
    else
        cout << s << "\n";
}
int main()
{
    int n = 4;
    string s = "ATGC";

    dnaPride(n, s);

    return 0;
}