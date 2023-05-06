#include <bits/stdc++.h>
using namespace std;

int numOfStrings(vector<string> &patterns, string word)
{
    int totalCount = 0;

    for (int i = 0; i < patterns.size(); i++)
    {
        if (word.find(patterns[i]) != string::npos)
            totalCount++;
    }
    return totalCount;
}

int main()
{
    vector<string> patterns = {"a", "abc", "bc", "d"};
    string word = "abc";

    cout << numOfStrings(patterns, word) << "\n";

    return 0;
}