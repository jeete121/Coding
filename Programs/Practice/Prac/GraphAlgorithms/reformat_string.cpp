#include <bits/stdc++.h>
using namespace std;

//function to reformat the string
string reformat(string s)
{
    int n = s.size();
    int digits = 0, character = 0;
    vector<char> d, c;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            digits++;
            d.push_back(s[i]);
        }
        else
        {
            character++;
            c.push_back(s[i]);
        }
    }
    string res = "";

    //sort the character arrays
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    //if length is even
    if (n % 2 == 0)
    {
        if (digits == character)
        {
            int flag = 0, l = 0, k = 0;
            for (int i = 0; i < n; i++)
            {
                if (flag == 0)
                {
                    s[i] = c[l];
                    l++;
                    flag = 1;
                }
                else
                {
                    s[i] = d[k];
                    k++;
                    flag = 0;
                }
            }
            return s;
        }
        else
            return res;
    }

    //if length is odd
    else
    {
        if (abs(digits - character) == 1)
        {
            if (digits > character)
            {
                int flag = 0, l = 0, k = 0;
                for (int i = 0; i < n; i++)
                {
                    if (flag == 0)
                    {
                        s[i] = d[l];
                        l++;
                        flag = 1;
                    }
                    else
                    {
                        s[i] = c[k];
                        k++;
                        flag = 0;
                    }
                }
                return s;
            }
            else
            {
                int flag = 0, l = 0, k = 0;
                for (int i = 0; i < n; i++)
                {
                    if (flag == 0)
                    {
                        s[i] = c[l];
                        l++;
                        flag = 1;
                    }
                    else
                    {
                        s[i] = d[k];
                        k++;
                        flag = 0;
                    }
                }
                return s;
            }
        }
        else
            return res;
    }
}

int main()
{
    string s = "a0b1c2";
    cout << reformat(s);
    return 0;
}