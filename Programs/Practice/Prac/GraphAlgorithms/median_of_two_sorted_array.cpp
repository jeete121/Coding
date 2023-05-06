#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1,
                              vector<int> &nums2)
{
    vector<int> v;
    int n = nums1.size(), m = nums2.size();
    int x = n + m;
    if (n == 0 && m == 0)
        return 0;
    if (n == 0)
    {
        double res = 0;
        if (m & 1)
            res = nums2[m / 2];
        else
        {
            res = nums2[m / 2] + nums2[m / 2 - 1];
            res = res / 2;
        }
        return res;
    }
    if (m == 0)
    {
        double res = 0;
        if (n & 1)
            res = nums1[n / 2];
        else
        {
            res = nums1[n / 2] + nums1[n / 2 - 1];
            res = res / 2;
        }
        return res;
    }
    if (x & 1)
    {
        x = (x + 1) / 2;
        int i = 0, j = 0;
        double res = 0;
        while (i < n || j < m)
        {
            if (i < n && j < m && nums1[i] < nums2[j])
            {
                x--;
                if (x == 0)
                {
                    res = nums1[i];
                    break;
                }
                i++;
            }
            else if (i < n && j < m)
            {
                x--;
                if (x == 0)
                {
                    res = nums2[j];
                    break;
                }
                j++;
            }
            else if (i < n)
            {
                x--;
                if (x == 0)
                {
                    res = nums1[i];
                    break;
                }
                i++;
            }
            else
            {
                x--;
                if (x == 0)
                {
                    res = nums2[j];
                    break;
                }
                j++;
            }
        }
        return res;
    }
    else
    {
        x = x / 2;
        int i = 0, j = 0;
        double res = 0;
        while (i < n || j < m)
        {
            if (i < n && j < m && nums1[i] < nums2[j])
            {
                x--;
                if (x == 0)
                {
                    res += nums1[i];
                    i++;
                    if (i < n)
                    {
                        if (i < n && j < m && nums1[i] < nums2[j])
                        {
                            res += nums1[i];
                        }
                        else
                            res += nums2[j];
                    }
                    else
                    {
                        res += nums2[j];
                    }
                    break;
                }
                else
                    i++;
            }
            else if (i < n && j < m)
            {
                x--;
                if (x == 0)
                {
                    res += nums2[j];
                    j++;
                    if (j < m)
                    {
                        if (nums2[j] < nums1[i])
                        {
                            res += nums2[j];
                        }
                        else
                            res += nums1[i];
                    }
                    else
                    {
                        res += nums1[i];
                    }
                    break;
                }
                else
                    j++;
            }
            else if (i < n)
            {
                x--;
                if (x == 0)
                {
                    res += nums1[i];
                    res += nums1[i + 1];
                    break;
                }
                i++;
            }
            else
            {
                x--;
                if (x == 0)
                {
                    res += nums2[j];
                    res += nums2[j + 1];
                    break;
                }
                j++;
            }
        }
        return res / 2;
    }
}
int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2);

    return 0;
}
