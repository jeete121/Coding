#include <bits/stdc++.h>
using namespace std;

void swapBits(string &str)
{

    for (int i = 0; i < str.size(); i += 2)
    {
        swap(str[i], str[i + 1]);
    }
}
int main()
{
    string str = "10101010";

    swapBits(str);
    cout << str << "\n";
}