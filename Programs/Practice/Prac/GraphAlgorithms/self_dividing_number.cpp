#include <bits/stdc++.h>
using namespace std;

// check number isSelfDividing
bool isSelfDividing(int n) 
{
        // till 9 all are self dividing
        if (n < 9)
            return true;
        int tmp = n;
        // iterate till 0
        while (tmp != 0) {
            int mode = tmp % 10;
            // if mode 0 then
            if (mode == 0)
                return false;
            // if not then false
            if (n % mode != 0)
                return false;
            tmp /= 10;
        }
        return true;
}
//function to find selft dividing number
vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> list;
    // iterate from to till end
    for (int i = left; i <= right; i++) {
        // is true then add into result
        if (isSelfDividing(i))
         list.push_back(i);
    }
        return list;
}

int main()
{
    int start = 1;
    int end = 22;
    vector<int> sdN= selfDividingNumbers(start, end);
    for(int i=0;i<sdN.size();i++)
       cout<<sdN[i]<<" ";
}

