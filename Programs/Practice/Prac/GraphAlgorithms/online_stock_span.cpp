#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    vector<pair<int, int>> v;
    int x = -1;

    StockSpanner()
    {
        v.push_back({x, INT_MAX});
    }

    int next(int price)
    {
        x++;
        while (!v.empty() && v.back().second <= price)
            v.pop_back();
        int res = x - v.back().first;
        v.push_back({x, price});
        return res;
    }
};

int main()
{
    StockSpanner S;

    cout << "[";
    cout << S.next(100) << ", ";
    cout << S.next(80) << ", ";
    cout << S.next(60) << ", ";
    cout << S.next(70) << ", ";
    cout << S.next(60) << ", ";
    cout << S.next(75) << ", ";
    cout << S.next(85);
    cout << "]";

    return 0;
}