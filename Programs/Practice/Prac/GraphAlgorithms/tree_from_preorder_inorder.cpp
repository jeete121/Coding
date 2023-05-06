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

int prestart;
TreeNode *buildTree(vector<int> &preorder,vector<int> &inorder,
      int instart,int inend)
{
        if(instart>inend)
              return NULL;
        TreeNode *root=new TreeNode(preorder[prestart++]);
        if(instart==inend)
              return root;
        int k=0;
        for(int i=instart;i<=inend;i++)
        {
            if(inorder[i]==root->data)
            {
                k=i;
                break;
            }
        }
        
        root->left=buildTree(preorder,inorder,instart,k-1);
        root->right=buildTree(preorder,inorder,k+1,inend);
        return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
        prestart=0;
        if(preorder.size()==0)
              return NULL;
        return buildTree(preorder,inorder,0,inorder.size()-1);
}

void printTree(TreeNode *root)
{
    queue<TreeNode*>q;
    q.push(root);
    vector<string> vec;
    while(!q.empty())
     {
         root=q.front();
         q.pop();
         if(root==NULL)
            vec.push_back("null");
         else
            vec.push_back(to_string(root->data));
        if(root!=NULL)
          {
              q.push(root->left);
              q.push(root->right);
          }
     }
     int j=vec.size()-1;
     while(j>0&&vec[j]=="null")
        j--;
      vec.resize(j);
      for(int i=0;i<j;i++)
        cout<<vec[i]<<",";
      cout<<vec[j];
}
int main()
{
  vector<int> preorder ={3,9,20,15,7};
  vector<int> inorder = {9,3,15,20,7};
  TreeNode *root=buildTree(preorder,inorder);
  printTree(root);
  return 0;
}
