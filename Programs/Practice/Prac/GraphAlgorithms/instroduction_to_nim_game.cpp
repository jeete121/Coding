#include <bits/stdc++.h>
using namespace std;

string nimGame(vector<int> pile)
{
    int res = pile[0];
    for (int i = 1; i < pile.size(); i++)
        res = res ^ pile[i];
    if (res != 0)
        return "First";
    return "Second";
}

int main()
{

    vector<int> pile = {2, 1, 4};

    cout << nimGame(pile);

    return 0;
}
