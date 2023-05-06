#include <bits/stdc++.h>
using namespace std;

class MyCalendar
{
public:
    vector<pair<int, int>> bookings;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        int l = bookings.size();
        for (int i = 0; i < l; i++)
        {
            if (start >= bookings[i].second || end <= bookings[i].first)
                continue;
            else
                return false;
        }
        bookings.push_back(make_pair(start, end));
        return true;
    }
};

int main()
{
    MyCalendar myCalendar;
    cout << "[";
    if (myCalendar.book(10, 20))
        cout << "true, ";
    else
        cout << "false, ";

    if (myCalendar.book(15, 25))
        cout << "true, ";
    else
        cout << "false, ";
    if (myCalendar.book(20, 30))
        cout << "true";
    else
        cout << "false";
    cout << "]";
    return 0;
}
