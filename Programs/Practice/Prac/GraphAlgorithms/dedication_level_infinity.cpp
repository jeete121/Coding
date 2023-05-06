#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

void dedicationLevel(int n, vector<pair<string, int>> &v)
{

    sort(v.begin(), v.end(), cmp);
    cout << v[0].first << "\n";
    cout << v[1].first << "\n";
    cout << v[2].first << "\n";
}
int main()
{
    int n = 7;
    vector<pair<string, int>> v = {{"Darshan", 78},
                                   {"Harshad", 90},
                                   {"Jaimin", 87},
                                   {"Nirav", 88},
                                   {"Hardik", 1},
                                   {"Fenil", 70},
                                   {"Lovlin", 5}};

    dedicationLevel(n, v);

    return 0;
}