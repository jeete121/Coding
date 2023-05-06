#include <bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word)
{
    int n = word.size();
    if (n == 0)
        return true;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (word[i] >= 'A' && word[i] <= 'Z')
            cnt++;
    if (cnt == 0 || cnt == n)
        return true;
    else
    {
        if (word[0] >= 'A' && word[0] <= 'Z')
        {
            for (int i = 1; i < n; i++)
                if (word[i] >= 'A' && word[i] <= 'Z')
                    return false;
            return true;
        }
        else
            return false;
    }
}

int main()
{
    string str = "USA";
    if (detectCapitalUse(str))
        cout << "true";
    else
        cout << "false";
    return 0;
}