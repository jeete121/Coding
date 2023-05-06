#include <bits/stdc++.h>
using namespace std;

bool hasGroupsSizeX(vector<int> &deck)
{
    int hash[10001] = {0};
    for (int i = 0; i < deck.size(); i++)
        hash[deck[i]]++;
    int min = INT_MAX;
    for (int i = 0; i < 10001; i++)
        if (hash[i] > 0)
        {
            if (hash[i] < min)
                min = hash[i];
        }
    int flag = 0, k = min;
    if (min == 1)
        return false;
    else
    {
        for (int i = 0; i < 10001; i++)
        {
            if (hash[i] > 0)
            {
                for (int j = min; j >= 2; j--)
                {
                    if (hash[i] % j == 0 && hash[i] != min)
                    {
                        k = j;
                        if (min % k == 0)
                            break;
                    }
                }
            }
        }
        for (int i = 0; i < 10001; i++)
        {
            if (hash[i] > 0)
            {
                if (hash[i] % k != 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0 && deck.size() > 1)
            return true;
        else
            return false;
    }
}

int main()
{
    vector<int> deck = {1, 2, 3, 4, 4, 3, 2, 1};
    if (hasGroupsSizeX(deck))
        cout << "true";
    else
        cout << "false";
    return 0;
}