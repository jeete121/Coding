#include <bits/stdc++.h>
using namespace std;

void harryString(string s)
{
    int cnt = 0;
    vector<char> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {

            v.push_back(s[i]);
            cnt++;
        }
    }
    if (cnt == 0)
        cout << "Good\n";
    else
    {
        int i = 0;
        int flag1 = 0, flag2 = 0;
        while (i < v.size() - 1)
        {
            if (v[i] <= v[i + 1])
                i++;
            else
            {
                flag1 = 1;
                break;
            }
        }
        if (flag1 == 0)
            cout << "Good\n";
        else
        {
            int i = 0;
            while (i < v.size() - 1)
            {
                if (v[i] >= v[i + 1])
                    i++;
                else
                {
                    flag2 = 1;
                    break;
                }
            }
            if (flag2 == 0)
                cout << "Worst\n";
            else
                cout << "Bad\n";
        }
    }
}
int main()
{

    string s = "discount";

    harryString(s);

    return 0;
}