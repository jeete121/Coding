#include <bits/stdc++.h>
using namespace std;

vector<string> readBinaryWatch(int num)
{
    vector<string> res;
    char str[10];
    for (int i = 0; i < 1 << 10; i++)
    {
        int s = 0;
        for (int j = 0; j < 10; j++)
        {
            if (i >> j & 1)
            {
                s++;
            }
        }
        if (s == num)
        {
            int a = i >> 6, b = i & 63;
            if (a < 12 && b < 60)
            {

                string str = "";
                if (b < 10)
                    str = str + to_string(a) + ":" + "0" + to_string(b);
                else
                    str = str + to_string(a) + ":" + to_string(b);

                res.push_back(str);
            }
        }
    }
    return res;
}

int main()
{
    int n = 1;

    vector<string> res = readBinaryWatch(n);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}