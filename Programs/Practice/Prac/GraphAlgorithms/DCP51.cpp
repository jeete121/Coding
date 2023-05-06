#include <bits/stdc++.h>
using namespace std;

int getRandomNumber(int k)
{
    return rand() % k + 1;
}

vector<int> shuffleCardDeck()
{
    vector<int> cards;
    for (int x = 0; x < 52; x++)
    {
        cards.push_back(x);
    }

    for (int i : cards)
    {

        int newPos = i + getRandomNumber(52 - i - 1);
        int temp = cards[newPos];
        cards[newPos] = cards[i];
        cards[i] = temp;
    }
    return cards;
}
int main()
{

    vector<int> cards = shuffleCardDeck();
    for (int j = 0; j < cards.size(); j++)
    {
        cout << cards[j] << " ";
    }
}