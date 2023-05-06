#include <bits/stdc++.h>
using namespace std;

//function to find the gcd of
//two numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
string gcdOfStrings(string str1, string str2)
{
    if (str1 + str2 != str2 + str1)
        return "";
    return str1.substr(0, gcd(str1.size(), str2.size()));
}

int main()
{
    string str1 = "ABCABC", str2 = "ABC";
    cout << gcdOfStrings(str1, str2);
    return 0;
}