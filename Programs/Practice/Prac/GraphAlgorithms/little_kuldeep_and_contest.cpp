#include <bits/stdc++.h>
using namespace std;

void littleContest(int m, vector<string> &str)
{
    vector<pair<double, double>> v;
    for (int j = 0; j < m; j++)
    {
        string s = str[j];

        string start, end;
        int i = 0;
        int n = s.size();
        while (s[i] != '-')
        {
            if (s[i] == ':')
                start += '.';
            else
                start += s[i];
            i++;
        }
        i++;
        while (i < n)
        {
            if (s[i] == ':')
                end += '.';
            else
                end += s[i];
            i++;
        }
        stringstream str1(start);
        double x = 0.0;
        str1 >> x;
        stringstream str2(end);
        double y = 0.0;
        str2 >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());
    int flag = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i].second > v[i + 1].first)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Who needs a moderator?\n";
    else
        cout << "Will need a moderator!\n";
}
int main()
{
    int m = 2;
    vector<string> str = {"11:00-13:30", "13:00-13:45"};

    littleContest(m, str);

    return 0;
}