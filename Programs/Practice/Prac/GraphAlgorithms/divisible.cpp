#include <bits/stdc++.h>
using namespace std;

int last(int n)
{
    int x;
    while (n)
    {
        x = n % 10;
        n = n / 10;
    }
    return x;
}
int first(int n)
{
    return n % 10;
}
bool divide(string s, int p)
{
    int n = s.size();
    string x = "";
    x += s[0];
    x += s[1];
    int i = 2;
    int l;
    while (i < n)
    {
        stringstream sstream(x);
        int y = 0;
        sstream >> y;
        l = y % p;
        x = "";
        if (l == 0 && i < n)
        {
            x += s[i];
            i++;
            if (i < n)
                x += s[i];
            i++;
        }
        else if (l != 0 && i < n)
        {
            x += to_string(l);
            x += s[i];
            i++;
        }
    }
    stringstream sstream(x);
    int y = 0;
    sstream >> y;
    l = y % p;
    if (l == 0)
        return true;
    return false;
}

void divisible(int n, int a[])
{

    string str = "";
    for (int i = 0; i < n / 2; i++)
    {
        int x = last(a[i]);
        str += to_string(x);
    }
    for (int i = n / 2; i < n; i++)
    {
        int x = first(a[i]);
        str += to_string(x);
    }

    bool flag = divide(str, 11);
    if (flag)
        cout << "OUI\n";
    else
        cout << "NON\n";
}
int main()
{
    int n = 6;
    int a[n] = {15478, 8452, 8232, 874, 985, 4512};

    divisible(n, a);

    return 0;
}