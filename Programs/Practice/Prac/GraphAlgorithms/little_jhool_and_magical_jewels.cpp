#include <bits/stdc++.h>
using namespace std;

int magicalJewels(string s)
{

    int n = s.size();
    int a[4] = {0};
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'r')
            a[0]++;
        else if (s[i] == 'u')
            a[1]++;
        else if (s[i] == 'b')
            a[2]++;
        else if (s[i] == 'y')
            a[3]++;
    }
    sort(a, a + 4);
    return a[0];
}
int main()
{

    string s = "rrrruubbbyy";

    cout << magicalJewels(s) << "\n";

    return 0;
}