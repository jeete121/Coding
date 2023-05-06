#include <bits/stdc++.h>
using namespace std;

//function to find the minimum rooms
//required
int minimumRooms(vector<vector<int>> &arr)
{
    vector<int> startTime;
    vector<int> endTime;
    for (int i = 0; i < arr.size(); i++)
    {
        startTime.push_back(arr[i][0]);
        endTime.push_back(arr[i][1]);
    }

    //sort the startTime array
    sort(startTime.begin(), startTime.end());

    //sort the endTime array
    sort(endTime.begin(), endTime.end());

    int start = 0, end = 0;
    int maxRooms = 0, count = 0;

    while (start < startTime.size() || end < endTime.size())
    {
        //if start time reach end of the startTime
        //then break
        if (start >= startTime.size())
        {
            break;
        }
        if (startTime[start] < endTime[end])
        {
            count++;
            start++;
        }
        else
        {
            count--;
            end++;
        }

        //update maximum rooms
        maxRooms = max(maxRooms, count);
    }
    return maxRooms;
}
int main()
{
    vector<vector<int>> arr = {{30, 75}, {0, 50}, {60, 150}};

    int ans = minimumRooms(arr);

    cout << ans << "\n";

    return 0;
}

//Time Complexity: O(nlogn)
