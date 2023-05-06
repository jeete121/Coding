#include <bits/stdc++.h>
using namespace std;

bool possibleBipartition(int N, vector<vector<int>> &dislikes)
{
    vector<int> arr[N + 1];

    //make the graph
    for (int i = 0; i < dislikes.size(); i++)
    {
        int a = dislikes[i][0];
        int b = dislikes[i][1];
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    //mark all as side -1
    vector<int> side(N + 1, -1);
    queue<int> q;
    bool flag = true;

    //iterate for all values 
    for (int i = 1; i <= N; i++)
    {

        //if sie is -1
        if (side[i] == -1)
        {

            //mark side as 0
            side[i] = 0;

            //add into the queue
            q.push(i);

            //iterate till the queue is not empty
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                //itearte for all adjacent of the current node
                for (int child : arr[curr])
                {

                    //if side is -1
                    if (side[child] == -1)
                    {
                        //then mark side as opposite of
                        //the parent
                        side[child] = side[curr] ^ 1;
                        q.push(child);
                    }

                    //else update flag
                    else
                        flag &= side[child] != side[curr];
                }
            }
        }
    }
    return flag;
}

int main()
{
    int N = 4;
    vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};

    if (possibleBipartition(N, dislikes))
        cout << "true";
    else
        cout << "false";
    return 0;
}