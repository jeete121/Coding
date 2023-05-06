#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b)
{
    int n = a.size(), m = b.size();
    if (n != m)
        return n < m;
    return a < b;
}
vector<string> bigSorting(vector<string> unsorted)
{
    sort(unsorted.begin(), unsorted.end(), comp);
    return unsorted;
}

int main()
{

    int n = 6;

    vector<string> unsorted = {"31415926535897932384626433832795", "1",
                               "3",
                               "10",
                               "3",
                               "5"};

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << "\n";
        }
    }
    cout << "\n";

    return 0;
}
