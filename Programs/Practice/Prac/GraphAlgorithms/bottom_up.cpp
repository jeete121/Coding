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


vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
        vector<vector<int>> res;
        vector<int> x;
        if(root==NULL)
               return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                root=q.front();
                x.push_back(root->data);
                q.pop();
                if(root->left)
                       q.push(root->left);
                if(root->right)
                       q.push(root->right);
            }
           res.push_back(x);
        x.clear();
        }
        reverse(res.begin(),res.end());
         return res;
}
int main()
{

    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    vector<vector<int>> order=levelOrderBottom(root);

    cout<<"[";
    for(int i=0;i<order.size();i++)
      {
          cout<<"[";
          for(int j=0;j<order[i].size();j++)
            {
                cout<<order[i][j];
                if(j!=order[i].size()-1)
                  cout<<",";
            }
         cout<<"]";
         if(i!=order.size()-1)
           cout<<",";
      }
      return 0;

}