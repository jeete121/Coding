#include <bits/stdc++.h>
using namespace std;

bool checkSubsequence(string s1, string s2)
{
    int currentIndex = 0;
    for (int index = 0; index < s1.length(); index++)
    {
        char currentChar = s1[index];
        currentIndex = s2.find(currentChar, currentIndex);
        if (currentIndex == -1)
        {
            return false;
        }
    }
    return true;
}
int main()
{

    string s1 = "rahul";
    string s2 = "allgirlsallhunontheplanet";
    if (checkSubsequence(s1, s2))
        cout << "Love you too\n";
    else
        cout << "We are only friends\n";

    return 0;
}
