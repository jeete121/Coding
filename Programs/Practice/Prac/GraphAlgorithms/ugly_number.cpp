#include <bits/stdc++.h>
using namespace std;

bool isUgly(int n)
{

    if (n <= 0)
        return false;
    set<int> st;
    while (n % 2 == 0)
    {
        st.insert(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            st.insert(i);
            n = n / i;
        }
    }
    if (n > 2)
        st.insert(n);
    if (st.size() > 3)
        return false;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        if (*it != 2 && *it != 3 && *it != 5)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 6;
    if (isUgly(n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}