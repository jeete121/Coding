#include <bits/stdc++.h>
using namespace std;

int numTeams(vector<int> &rating)
{
    int N = rating.size();
    vector<int> large(N, 0);
    vector<int> small(N, 0);

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (rating[i] > rating[j])
                large[i]++;
            else
                small[i]++;
        }
    }

    int team = 0;

    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            if (rating[i] > rating[j])
                team += large[j];
            else
                team += small[j];
        }
    }

    return team;
}
int main()
{
    vector<int> rating = {2, 5, 3, 4, 1};

    cout << numTeams(rating);

    return 0;
}