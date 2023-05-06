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
//Function to find inorder Traversal
//of tree
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *temp=root;
    while(temp!=NULL||!st.empty())
      {
          if(temp!=NULL)
            {
                res.push_back(temp->data);
                st.push(temp);
                temp=temp->left;
            }
          else
          {
              temp=st.top();
              st.pop();
              temp=temp->right;
          }
          
      }
      return res;
}
int main()
{
    TreeNode *tree=new TreeNode(1);
    tree->right=new TreeNode(2);
    tree->right->left=new TreeNode(3);
    cout<<"Preorder Traversal\n";
    vector<int> res=preorderTraversal(tree);
    int n=res.size();
    for(int i=0;i<n;i++)
       cout<<res[i]<<" ";
    
    return 0;
}
//Time Complexity: O(n)
