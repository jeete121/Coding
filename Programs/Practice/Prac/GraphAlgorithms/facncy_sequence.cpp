#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

unsigned long modPow(unsigned long x, int y)
{
    unsigned long tot = 1, p = x;
    for (; y; y >>= 1)
    {
        if (y & 1)
            tot = (tot * p) % mod;
        p = (p * p) % mod;
    }
    return tot;
}

class Fancy
{
public:
    unsigned long seq[100001];
    unsigned int length = 0;
    unsigned long increment = 0;
    unsigned long mult = 1;
    Fancy()
    {
    }

    void append(int val)
    {
        seq[length++] = (((mod + val - increment) % mod) * modPow(mult, mod - 2)) % mod;
    }
    void addAll(int inc)
    {
        increment = (increment + inc % mod) % mod;
    }

    void multAll(int m)
    {
        mult = (mult * m % mod) % mod;
        increment = (increment * m % mod) % mod;
    }

    int getIndex(int idx)
    {

        if (idx >= length)
        {
            return -1;
        }
        else
        {
            return ((seq[idx] * mult) % mod + increment) % mod;
        }
    }
};

int main()
{
    Fancy fancy;
    fancy.append(2);
    fancy.addAll(3);
    fancy.append(7);
    fancy.multAll(2);
    cout << fancy.getIndex(0) << ", ";
    fancy.addAll(3);
    fancy.append(10);
    fancy.multAll(2);
    cout << fancy.getIndex(0) << ", ";
    cout << fancy.getIndex(1) << ", ";
    cout << fancy.getIndex(2);

    return 0;
}