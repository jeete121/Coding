#include <bits/stdc++.h>
using namespace std;

bool is_smart_number(int num)
{
    int val = (int)sqrt(num);
    if ((double)num / val == val)
        return true;
    return false;
}

int main()
{

    int num = 4;

    bool ans = is_smart_number(num);
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}
