#include <bits/stdc++.h>
using namespace std;

int camelcase(string s)
{

    long long l, count = 0;
    l = s.size();
    for (long long i = 0; i < l; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
            count++;
    }
    return count + 1;
}
int main()
{
    string s = "saveChangesInTheEditor";
    cout << camelcase(s);

    return 0;
}
