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
//Function to find the level order
//traversal of the tree
vector<vector<int>> levelOrderTraversal(TreeNode *root)
{
  vector<vector<int>> res;
  if(root==NULL)
      return res;
  queue<TreeNode*> q;
  q.push(root);
  //Run loop till queue is not empty
  while(!q.empty())
    {
         int len=q.size();
         vector<int> vec;
         while(len--)
         {
           root=q.front();
           q.pop();
           vec.push_back(root->data);
             if(root->left)
                q.push(root->left);
             if(root->right)
                q.push(root->right);
         } 
         res.push_back(vec);
    }
    return res;
}
int main()
{
    TreeNode *tree=new TreeNode(1);
    tree->left=new TreeNode(4);
    tree->right=new TreeNode(2);
    tree->right->left=new TreeNode(3);
    cout<<"Level Order Traversal\n";
    vector<vector<int>> res=levelOrderTraversal(tree);
    int n=res.size();
    cout<<"[\n";
    for(int i=0;i<n;i++)
       {
           cout<<" [";
           for(int j=0;j<res[i].size();j++)
              {
                  cout<<res[i][j];
                  if(j!=res[i].size()-1)
                     cout<<",";
              }
            cout<<"]";
          if(i!=n-1)
          {
              cout<<",";
              cout<<"\n";
          }
       }
    cout<<"\n]";
    return 0;
}
//Time Complexity: O(n)
