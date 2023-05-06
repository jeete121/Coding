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

//function to check for same tree
bool isSameTree(TreeNode* p, TreeNode* q) 
{
       if(p==NULL && q==NULL)
              return true;
       if((p==NULL &&q!=NULL)||(p!=NULL && q==NULL))
              return false;
       if(p->data!=q->data)
              return false;
        return isSameTree(p->left,q->left)
             &&isSameTree(p->right,q->right);
}

    
int main()
{

    TreeNode *root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);

    
    TreeNode *root2=new TreeNode(1);
    root2->left=new TreeNode(2);
    root2->right=new TreeNode(3);

    if(isSameTree(root1,root2))
      cout<<"true";
    else
      cout<<"false";
    
     return 0;
    
}
