#include <bits/stdc++.h>
using namespace std;

vector<int> constructRectangle(int area)
{
    int w = sqrt(area);
    while (area % w)
    {
        w--;
    }
    return {area / w, w};
}

int main()
{
    int area = 4;

    vector<int> res = constructRectangle(area);

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