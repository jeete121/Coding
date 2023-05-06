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


vector<int> v;
void dfs(TreeNode *root)
{
        if(root==NULL)
               return ;
        dfs(root->left);
        v.push_back(root->data);
        dfs(root->right);
}
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
{
        vector<int> res;
        v.clear();
        dfs(root1);
        for(int i=0;i<v.size();i++)
               res.push_back(v[i]);
        v.clear();
        dfs(root2);
        
        for(int i=0;i<v.size();i++)
               res.push_back(v[i]);
        sort(res.begin(),res.end());
        return res;
}

int main()
{
   TreeNode *root1=new TreeNode(2);
   root1->left=new TreeNode(1);
   root1->right=new TreeNode(4);

   TreeNode *root2=new TreeNode(1);
   root2->left=new TreeNode(0);
   root2->right=new TreeNode(3);

   vector<int> arr=getAllElements(root1,root2);
   for(int i=0;i<arr.size();i++)
      cout<<arr[i]<<" ";
    
   return 0;
}