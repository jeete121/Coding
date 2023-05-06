#include <bits/stdc++.h>
using namespace std;

int minTimeToType(string word)
{

    int totalTime = 0;

    //initially start character is 'a'
    int start = 'a';

    //itearate through whole string
    for (int i = 0; i < word.size(); i++)
    {
        //check for which direction we need to go
        int clockDir = abs((word[i] - 'a') - (start - 'a'));

        //update the clockdir as min of clockwise and
        //anticlockwise
        clockDir = min(clockDir, 26 - clockDir);

        //add clockDir value to final result +1 for type that character
        totalTime += clockDir + 1;

        //update the start character as current character
        start = word[i];
    }

    return totalTime;
}

int main()
{
    string word = "bza";

    cout << minTimeToType(word) << "\n";

    return 0;
}