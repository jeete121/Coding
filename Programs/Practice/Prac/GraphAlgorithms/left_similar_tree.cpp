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

vector<int> res1,res2;
void leafnodes(TreeNode *root,vector<int> &res)
{

    //base case if tree is empty
    if(root==NULL)
        return;

     //if leaf node
    if(root->left==NULL && root->right==NULL)
      {
            res.push_back(root->data);
            return ;
      }

      //call for left subtree
     if(root->left)
            leafnodes(root->left,res);
     
     //call for right subtree
      if(root->right)
            leafnodes(root->right,res);
        
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) 
{
      
        if(root1==NULL&& root2==NULL)
              return true;
        if(root1==NULL||root2==NULL)
               return false;
        leafnodes(root1,res1);
        leafnodes(root2,res2);
        if(res1.size()!=res2.size())
               return false;
        for(int i=0;i<res1.size();i++)
               if(res1[i]!=res2[i])
                      return false;
        return true;
        

}

int main()
{
    TreeNode *root1=new TreeNode(1);
    root1->left=new TreeNode(3);
    root1->right=new TreeNode(3);

    TreeNode *root2=new TreeNode(2);
    root2->left=new TreeNode(3);
    root2->right=new TreeNode(3);

    if(leafSimilar(root1,root2))
      cout<<"true";
    else
     cout<<"false";

    return 0;
}