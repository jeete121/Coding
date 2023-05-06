#include <bits/stdc++.h>
using namespace std;

void shortName(string s)
{
    int n = s.size();
    int i = 0, j;
    vector<string> v;
    string str = "";
    while (i < n)
    {
        j = i;
        str = "";
        while (i < n && s[i] != ' ')
        {
            str += s[i];
            i++;
        }
        i++;
        if (i == n + 1)
            v.push_back(str);
        else
        {
            str = "";
            str += s[j];
            str += '.';

            v.push_back(str);
        }
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
int main()
{
    string s = "Mohd Kafeel Khan";

    shortName(s);

    return 0;
}