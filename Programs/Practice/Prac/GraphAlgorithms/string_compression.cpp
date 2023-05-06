#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{
    int i = 0;
    int cnt = 1, n = chars.size();
    int l = 0;
    if (n == 0 || n == 1)
        return n;
    while (i < n - 1)
    {
        if (chars[i] == chars[i + 1])
            cnt++;
        else
        {
            chars[l++] = chars[i];
            if (cnt > 1)
            {
                string x = to_string(cnt);
                for (int j = 0; j < x.size(); j++)
                    chars[l++] = x[j];
            }
            cnt = 1;
        }
        i++;
    }
    chars[l++] = chars[n - 1];
    if (cnt > 1)
    {

        string x = to_string(cnt);

        for (int i = 0; i < x.size(); i++)
            chars[l++] = x[i];
    }
    chars.resize(l);
    return l;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << compress(chars);
    return 0;
}