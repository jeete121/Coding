#include <bits/stdc++.h>
using namespace std;

string invertedBitsNumber(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
            str[i] = '0';
        else
            str[i] = '1';
    }
    return str;
}
int main()
{
    string str = "11110000111100001111000011110000";

    cout << invertedBitsNumber(str) << "\n";

    return 0;
}