#include <bits/stdc++.h>
using namespace std;

string defangIPaddr(string address)
{
    string str = "";
    string ans = "";
    int n = address.size();
    for (int i = 0; i < n; i++)
    {
        if (address[i] != '.')
            str += address[i];
        else
        {
            ans += str;
            ans += "[.]";
            str = "";
        }
    }
    ans += str;
    return ans;
}

int main()
{
    string address = "1.1.1.1";
    cout << defangIPaddr(address);
    return 0;
}