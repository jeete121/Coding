#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<char, pair<int, int>> mp;

    mp['.'] = {1, 1};
    mp[','] = {1, 2};
    mp['?'] = {1, 3};
    mp['!'] = {1, 4};
    mp['1'] = {1, 5};
    //2
    mp['a'] = {2, 1};
    mp['b'] = {2, 2};
    mp['c'] = {2, 3};
    mp['2'] = {2, 4};
    //3
    mp['d'] = {3, 1};
    mp['e'] = {3, 2};
    mp['f'] = {3, 3};
    mp['3'] = {3, 4};
    //4
    mp['g'] = {4, 1};
    mp['h'] = {4, 2};
    mp['i'] = {4, 3};
    mp['4'] = {4, 4};
    //5
    mp['j'] = {5, 1};
    mp['k'] = {5, 2};
    mp['l'] = {5, 3};
    mp['5'] = {5, 4};
    //6
    mp['m'] = {6, 1};
    mp['n'] = {6, 2};
    mp['o'] = {6, 3};
    mp['6'] = {6, 4};
    //7
    mp['p'] = {7, 1};
    mp['q'] = {7, 2};
    mp['r'] = {7, 3};
    mp['s'] = {7, 4};
    mp['7'] = {7, 5};
    //8
    mp['t'] = {8, 1};
    mp['u'] = {8, 2};
    mp['v'] = {8, 3};
    mp['8'] = {8, 4};
    //9

    mp['w'] = {9, 1};
    mp['x'] = {9, 2};
    mp['y'] = {9, 3};
    mp['z'] = {9, 4};
    mp['9'] = {9, 5};
    //0
    mp['_'] = {0, 1};
    mp['0'] = {0, 2};

    string s = "hack";

    int cnt = 0;
    int n = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]].first != n)
        {
            cnt++;
            n = mp[s[i]].first;
            cnt += mp[s[i]].second;
        }
        else
        {
            cnt += mp[s[i]].second;
        }
    }
    cout << cnt << "\n";

    return 0;
}