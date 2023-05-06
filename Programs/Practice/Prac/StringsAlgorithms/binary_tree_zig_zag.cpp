#include <bits/stdc++.h>
using namespace std;
int main()
{

}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
        vector<vector<int>> res;
        if(root==NULL)
               return res;
        stack<TreeNode *> s1,s2;
        s1.push(root);
        bool flag=false;
        vector<int> x;
        while(!s1.empty())
         {
            TreeNode *temp=s1.top();
            s1.pop();
            if(temp)
            {
                x.push_back(temp->val);
                if(!flag)
                {
                    if(temp->left)
                           s2.push(temp->left);
                    if(temp->right)
                           s2.push(temp->right);
                }
                else
                {
                       
                    if(temp->right)
                           s2.push(temp->right);  
                      if(temp->left)
                           s2.push(temp->left);
                }
            }
           
            if(s1.empty())
            {
                flag=!flag;
                swap(s1,s2);
                 res.push_back(x);
            x.clear();
            }
         }
        return res;
}