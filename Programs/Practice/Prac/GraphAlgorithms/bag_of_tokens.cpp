#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int> &tokens, int P)
{
    //sort the array
    sort(tokens.begin(), tokens.end());
    int maxScore = 0;
    int currScore = 0;
    int start = 0, end = tokens.size() - 1;

    //apply two pointer
    while (start <= end)
    {
        if (P - tokens[start] >= 0)
        {
            P -= tokens[start];
            currScore += 1;
            maxScore = max(maxScore, currScore);
            start += 1;
        }
        else if (currScore >= 1)
        {
            P += tokens[end];
            currScore -= 1;
            end -= 1;
        }
        else
        {
            break;
        }
    }

    return maxScore;
}

int main()
{
    vector<int> tokens = {100, 200};
    int P = 150;

    cout << bagOfTokensScore(tokens, P);

    return 0;
}