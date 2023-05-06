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
TreeNode *LCA(TreeNode *root,int val1,int val2)
{
        if(root==NULL)
              return NULL;
        if(root->data==val1||root->data==val2)
               return root;
        TreeNode *leftLCA=LCA(root->left,val1,val2);
        TreeNode *rightLCA=LCA(root->right,val1,val2);
        if(leftLCA!=NULL&&rightLCA!=NULL)
              return root;
        if(leftLCA==NULL)
              return rightLCA;
        return leftLCA;
        
}
TreeNode* subtreeWithAllDeepest(TreeNode* root) 
{
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root==NULL)
              return NULL;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            vector<int> v;
            while(len--)
            {
                TreeNode *temp=q.front();
                q.pop();
                v.push_back(temp->data);
                if(temp->left)
                      q.push(temp->left);
                if(temp->right)
                       q.push(temp->right);
            }
            res.push_back(v);
        }
        vector<int> v=res[res.size()-1];
        if(v.size()==1)
        {
            TreeNode *ans=LCA(root,v[0],v[0]);
            return ans;
        }
         int x=v[0];
        int flag=0;
        TreeNode *ans=NULL;
        for(int i=1;i<v.size();i++) 
        {
          
            int y=v[i];
            ans=LCA(root,x,y);
            
            if(ans!=NULL)
             x=ans->data;
        } 
        return ans;
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
    TreeNode *root=new TreeNode(0);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(2);
    
    TreeNode *sub=subtreeWithAllDeepest(root);
    printTree(sub);
    return 0;

}