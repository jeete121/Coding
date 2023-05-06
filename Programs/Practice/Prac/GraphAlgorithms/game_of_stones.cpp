#include <bits/stdc++.h>
using namespace std;

string gameOfStones(int n)
{
    if (n % 7 == 0 || n % 7 == 1)
        return "Second";
    return "First";
}

int main()
{
    int n = 4;

    cout << gameOfStones(n);

    return 0;
}
