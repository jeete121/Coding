#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> friendRelationship(int n)
{
    vector<vector<char>> v1;
    for (int i = 1; i <= n; i++)
    {
        vector<char> v;
        for (int k = 0; k < i; k++)
            v.push_back('*');
        for (int j = 1; j <= 2 * n - 2 * i; j++)
            v.push_back('#');
        for (int k = 0; k < i; k++)
            v.push_back('*');
        v1.push_back(v);
    }
    return v1;
}
int main()
{

    int n = 5;

    vector<vector<char>> v1 = friendRelationship(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
            cout << v1[i][j];
        cout << "\n";
    }

    return 0;
}