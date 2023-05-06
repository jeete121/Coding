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

bool isEvenOddTree(TreeNode* root) 
{
        queue<TreeNode*>q;
        if(root==NULL)
               return true;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int len=q.size();
            vector<int> v;
            while(len>0&&flag==true)
            {
                root=q.front();
                if((root->data)%2==0)
                    return false;
                v.push_back(root->data);
                q.pop();
                if(root->left)
                      q.push(root->left);
                if(root->right)
                       q.push(root->right);
                len--;
            }
            if(flag==true)
            {
            for(int i=0;i<v.size()-1;i++)
              {
                 if(v[i]>=v[i+1])
                       return false;
              }
            }
            while(len>0&&flag==false)
            {
                root=q.front();
                if((root->data)&1)
                    return false;
                v.push_back(root->data);
                q.pop();
                if(root->left)
                      q.push(root->left);
                if(root->right)
                       q.push(root->right);
                 len--;
            }
            if(flag==false)
            {
             for(int i=0;i<v.size()-1;i++)
              {
                 if(v[i]<=v[i+1])
                       return false;
              }
            }
            flag=!flag;
        }
        return true;
}

int main()
{
   TreeNode *root=new TreeNode(5);
   root->left=new TreeNode(4);
   root->right=new TreeNode(2);
   root->left->left=new TreeNode(3);
   root->left->right=new TreeNode(3);
   root->right->left=new TreeNode(7);
 
   if(isEvenOddTree(root))
     cout<<"true";
   else
     cout<<"false";
    
  return 0;
   
}