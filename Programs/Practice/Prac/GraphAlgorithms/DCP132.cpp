#include <bits/stdc++.h>
using namespace std;

class HitCounter
{
public:
    HitCounter()
    {
        times.resize(300);
        hits.resize(300);
    }

    void hit(int timestamp)
    {
        int idx = timestamp % 300;
        if (times[idx] != timestamp)
        {
            times[idx] = timestamp;
            hits[idx] = 1;
        }
        else
        {
            ++hits[idx];
        }
    }
    int getHits(int timestamp)
    {
        int res = 0;
        for (int i = 0; i < 300; ++i)
        {
            if (timestamp - times[i] < 300)
            {
                res += hits[i];
            }
        }
        return res;
    }

private:
    vector<int> times, hits;
};

int main()
{
    HitCounter counter;

    counter.hit(1);

    counter.hit(2);

    counter.hit(3);
    cout << "[";
    cout << counter.getHits(4) << ", ";

    counter.hit(300);
    cout << counter.getHits(300) << ", ";

    cout << counter.getHits(301);
    cout << "]";
    return 0;
}