#include <bits/stdc++.h>
using namespace std;

int flip()
{

    return (rand() % 100) > 49 ? 0 : 1;
}
int coinCounter(int totalCoins)
{

    int totalRounds = 0;
    int coinsToFlip = totalCoins;
    while (coinsToFlip > 1)
    {
        int coins = coinsToFlip;
        for (int i = 0; i < coins; ++i)
        {
            if (flip() == 1)
            {

                --coinsToFlip;
            }
        }
        ++totalRounds;
    }
    return totalRounds;
}

int main()
{

    int numCoins = 100;
    int result = coinCounter(numCoins);

    cout << "Expected rounds to play: " << result << endl;

    return 0;
}