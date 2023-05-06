#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "{(a+b)+d+e+(e*f)}";

    int n = str.size();

    int len = 0, i = 0;
    while (i < n)
    {
        if (str[i] == '(' || str[i] == ')')
        {
            i++;
        }
        else if (str[i] == '{' || str[i] == '}')
        {
            i++;
        }
        else if (str[i] == '[' || str[i] == ']')
        {
            i++;
        }
        else
        {
            str[len] = str[i];
            i++;
            len++;
        }
    }
    str.resize(len);
    cout << "String after remove of brackets is " << str;
    return 0;
}