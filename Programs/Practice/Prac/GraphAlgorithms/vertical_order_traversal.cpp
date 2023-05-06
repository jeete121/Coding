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



map<int,vector<pair<int,int>>> mp;
void verticalTraversal(TreeNode *root,int x,int y)
{
    if(root==NULL)
               return;
     mp[x].push_back({y,root->data});

     //call for left subtree
     verticalTraversal(root->left,x-1,y+1);

     //call for right subtree
     verticalTraversal(root->right,x+1,y+1);
}
vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    verticalTraversal(root,0,0);
    vector<vector<int>> res;
     for(auto  m:mp)
     {
        // sort(m.second.begin(),m.second.end());
         vector<int>v;
         for(auto x:m.second)
               v.push_back(x.second);
        res.push_back(v);
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

  vector<vector<int>> arr=verticalTraversal(root);
  cout<<"[";
  for(int i=0;i<arr.size();i++)
    {
        cout<<"[";
        for(int j=0;j<arr[i].size();j++)
          {
              cout<<arr[i][j];
              if(j!=arr[i].size()-1)
                cout<<",";

          }
        cout<<"]";
        if(i!=arr.size()-1)
          cout<<",";
    }
  cout<<"]";
  return 0;
}