#include <bits/stdc++.h>
using namespace std;

bool isPathCrossing(string s)
{
    set<pair<int, int>> st;
    int n = s.size();
    st.insert(make_pair(0, 0));
    int x = 0, y = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N')
        {
            y++;
            int len = st.size();
            st.insert(make_pair(x, y));
            if (st.size() == len)
            {
                flag = 1;
                break;
            }
        }
        else if (s[i] == 'S')
        {
            y--;
            int len = st.size();
            st.insert(make_pair(x, y));
            if (st.size() == len)
            {
                flag = 1;
                break;
            }
        }
        else if (s[i] == 'E')
        {
            x++;
            int len = st.size();
            st.insert(make_pair(x, y));
            if (st.size() == len)
            {
                flag = 1;
                break;
            }
        }
        else
        {
            x--;
            int len = st.size();
            st.insert(make_pair(x, y));
            if (st.size() == len)
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        return true;
    return false;
}

int main()
{
    string path = "NESWW";
    if (isPathCrossing(path))
        cout << "true";
    else
        cout << "false";

    return 0;
}