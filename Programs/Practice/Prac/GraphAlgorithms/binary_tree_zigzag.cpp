#include <bits/stdc++.h>
using namespace std;


//struct for treenode
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

//function to find the zigzag level order
//traversal of binary tree
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
        vector<vector<int>> res;
        if(root==NULL)
               return res;

        stack<TreeNode *> s1,s2;
        s1.push(root);
        bool flag=false;
        vector<int> x;

        //iterate till stack1 is not empty
        while(!s1.empty())
         {
            TreeNode *temp=s1.top();
            s1.pop();
            if(temp)
            {
                x.push_back(temp->data);

                //if direction from left to right
                if(!flag)
                {
                    if(temp->left)
                           s2.push(temp->left);
                    if(temp->right)
                           s2.push(temp->right);
                }

                //if direction from right to left
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
                //change the direction
                flag=!flag;

                //swap both the stacks
                swap(s1,s2);
                //push the current level into the
                //final result
                 res.push_back(x);
            x.clear();
            }
         }
        return res;
}
int main()
{
  TreeNode *root=new TreeNode(3);
  root->left=new TreeNode(9);
  root->right=new TreeNode(20);
  root->right->left=new TreeNode(15);
  root->right->right=new TreeNode(7);

  vector<vector<int>> zig=zigzagLevelOrder(root);
  for(int i=0;i<zig.size();i++)
    {
        for(int j=0;j<zig[i].size();j++)
            cout<<zig[i][j]<<" ";
        cout<<"\n";
    }
}

