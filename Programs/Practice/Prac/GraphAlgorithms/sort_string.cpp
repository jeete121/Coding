#include <bits/stdc++.h>
using namespace std;

string  strSort(string s)
{
    sort(s.begin(),s.end());
    return s;
}
int main()
{
    string s = "ramsingh";
    cout<<strSort(s);
    return 0;
}