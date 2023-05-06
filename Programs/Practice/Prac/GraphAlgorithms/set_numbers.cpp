#include <bits/stdc++.h>
using namespace std;

int setNumbers(int n)
{

    int n1 = n;
    vector<int> v;
    while (n > 0)
    {

        v.push_back(n % 2);
        n = n / 2;
    }
    int f = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            f = 1;
            break;
        }
    }
    if (f == 0)
        return n1;
    else
    {
        int ans = 0;
        while (n1 > 0)
        {
            n1 = n1 / 2;
            ans = ans * 2 + 1;
        }
        return (ans - 1) / 2;
    }
}
int main()
{

    int n = 345;

    cout << setNumbers(n) << "\n";

    return 0;
}