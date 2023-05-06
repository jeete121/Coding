#include <bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target)
 {
    for(int i=0;i<matrix.size();i++)
        {
            if(binary_search(matrix[i].begin(),matrix[i].end(),target))
                  return true;
        }
        return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                 {2,5,8,12,19},
                                 {3,6,9,16,22},
                                 {10,13,14,17,24},
                                 {18,21,23,26,30}};
   int  target = 5;
   if(searchMatrix(matrix,target))
     cout<<"true";
   else
     cout<<"false";

   return 0;
}