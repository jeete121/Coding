#include <bits/stdc++.h>
using namespace std;

class MountainArray
{
public:
    vector<int> arr;
    MountainArray(vector<int> &arr)
    {
        this->arr = arr;
    }
    int length()
    {
        return arr.size();
    }
    int get(int index)
    {
        return arr[index];
    }
};
int findMountain(MountainArray mountainArr, int low, int high)
{
    int mid = (low + high) / 2;
    if ((mountainArr.get(mid) > mountainArr.get(mid - 1)) && (mountainArr.get(mid) > mountainArr.get(mid + 1)))
        return mid;
    else if ((mountainArr.get(mid + 1) > mountainArr.get(mid)))
        return findMountain(mountainArr, mid, high);
    return findMountain(mountainArr, low, mid);
}
int findInMountainLeft(int target, MountainArray &mountainArr, int low, int high)
{
    if (high < low)
        return -1;
    if (high == low)
        if (mountainArr.get(high) == target)
            return high;
    if (high == low + 1)
    {
        if (mountainArr.get(low) == target)
            return low;
        if (mountainArr.get(high) == target)
        {
            return high;
        }
        return -1;
    }
    int mid = (low + high) / 2;

    if (mountainArr.get(mid) == target)
        return mid;
    else if (mountainArr.get(mid) > target)
        return findInMountainLeft(target, mountainArr, low, mid - 1);
    return findInMountainLeft(target, mountainArr, mid + 1, high);
}
int findInMountainRight(int target, MountainArray &mountainArr, int low, int high)
{

    if (high < low)
        return -1;
    if (high == low)
        if (mountainArr.get(high) == target)
            return high;
    if (high == low + 1)
    {
        if (mountainArr.get(low) == target)
            return low;
        if (mountainArr.get(high) == target)
        {
            return high;
        }
        return -1;
    }
    int mid = (low + high) / 2;

    if (mountainArr.get(mid) == target)
        return mid;
    else if (mountainArr.get(mid) < target)
        return findInMountainRight(target, mountainArr, low, mid - 1);
    return findInMountainRight(target, mountainArr, mid + 1, high);
}
int findInMountainArray(int target, MountainArray &mountainArr)
{
    int high = mountainArr.length() - 1;
    int low = 0;
    int mntIdx = findMountain(mountainArr, low, high);

    int isInLeftIdx = findInMountainLeft(target, mountainArr, low, mntIdx);

    if (-1 == isInLeftIdx)
        return findInMountainRight(target, mountainArr, mntIdx, high);
    return isInLeftIdx;
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 3, 1};
    int target = 3;

    MountainArray mountarray(array);

    cout << findInMountainArray(target, mountarray);

    return 0;
}