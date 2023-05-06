#include <bits/stdc++.h>
using namespace std;

string angryProfessor(int k, vector<int> a)
{
    int m = 0;
    int n = a.size();
    for (int j = 0; j < n; j++)
    {
        if (a[j] <= 0)
        {
            m++;
        }
    }
    if (m < k)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}
int main()
{

    int n = 4, k = 3;
    vector<int> a = {-1, -3, 4, 2};
    cout << angryProfessor(k, a);
    return 0;
}
