#include <bits/stdc++.h>
using namespace std;

string digitProblem(string x, int k)
{
    int n = x.size();
    int cnt = 0;
    for (int i = 0; i < n && k; i++)
    {

        if (x[i] != '9')
        {
            x[i] = '9';
            cnt++;
        }
        if (cnt == k)
            break;
    }
    return x;
}
int main()
{
    string x = "4483";
    int k = 2;

    cout << digitProblem(x, k) << "\n";

    return 0;
}