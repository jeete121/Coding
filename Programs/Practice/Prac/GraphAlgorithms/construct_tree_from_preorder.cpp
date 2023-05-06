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

TreeNode* bstFromPreorder(vector<int>& preorder) 
{
     int n=preorder.size();
     if(n==0)
         return NULL;
     vector<int> Left,Right;
     int head=preorder[0];
     for(int i=1;i<n;i++)
     {
         if(preorder[i]<head)
             Left.push_back(preorder[i]);
         else
             Right.push_back(preorder[i]);
     }
     TreeNode *root=new TreeNode(head);
     root->left= bstFromPreorder(Left);
     root->right= bstFromPreorder(Right);
     return root;
}

//function to print the tree
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
    vector<int> preorder={8,5,1,7,10,12};
    TreeNode *root=bstFromPreorder(preorder);

    printTree(root);
    return  0;

}