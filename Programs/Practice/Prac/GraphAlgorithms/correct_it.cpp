#include <bits/stdc++.h>
using namespace std;

string correctIt(long long n)
{
    set<long long> st;
    st.insert(n);
    int flag = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            if (st.find(n) != st.end())
            {
                flag = 1;
                break;
            }
        }
        else
        {
            n = n * 3 + 1;
            if (st.find(n) != st.end())
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
        return "YES";
    else
        return "NO";
}
int main()
{

    long long n = 21;

    cout << correctIt(n) << "\n";
    return 0;
}