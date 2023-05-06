#include <bits/stdc++.h>
using namespace std;

vector<int> shortestToChar(string s, char c)
{

    int n = s.size();
    int left[n + 1], right[n + 1];

    int index = -1;
    if (s[0] == c)
    {
        index = 0;
    }
    left[0] = index;

    //find the index for left of the current index
    for (int i = 1; i < n; i++)
    {
        if (s[i] != c)
        {
            left[i] = index;
        }
        else
        {
            index = i;
            left[i] = index;
        }
    }
    index = -1;
    if (s[n - 1] == c)
    {
        index = n - 1;
    }
    right[n - 1] = index;

    //find the index for right of
    //current index
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] != c)
        {
            right[i] = index;
        }
        else
        {
            index = i;
            right[i] = index;
        }
    }

    vector<int> res;

    //find the shortest distance to
    //each index
    for (int i = 0; i < n; i++)
    {

        //if left and right both exist
        if (left[i] != -1 && right[i] != -1)
        {
            int x = abs(i - left[i]);
            int y = abs(i - right[i]);
            res.push_back(min(x, y));
        }

        //if right exist
        else if (left[i] == -1 && right[i] != -1)
        {
            res.push_back(abs(i - right[i]));
        }

        //if left exist
        else if (right[i] == -1 && left[i] != -1)
        {
            res.push_back(abs(i - left[i]));
        }
    }
    return res;
}

int main()
{

    string s = "aaab";
    char c = 'b';

    vector<int> res = shortestToChar(s, c);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}