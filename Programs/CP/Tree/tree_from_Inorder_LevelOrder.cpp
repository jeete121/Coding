#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left,*right;
};
Node *newNode(int key)
{
    Node *node=new Node;
    node->key=key;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}
void inorderTraversal(Node *root)
 {
     if(root==nullptr)
       return;
    inorderTraversal(root->left);
    cout<<root->key<<" ";
    inorderTraversal(root->right);

 }
 Node *buildTree(int inorder[],int start,int end,unordered_map<int,int> ump)
 {
     if(start>end)
       return nullptr;
     int index=start;
     for(int j=start+1;j<=end;j++)
       {
            if(ump[inorder[j]]<ump[inorder[index]])
               index=j;  
       }
    Node *root=newNode(inorder[index]);
    root->left=buildTree(inorder,start,index-1,ump);
    root->right=buildTree(inorder,index+1,end,ump);
    return root;
 }
 Node *buildTree(int in[],int level[],int n)
 {
     unordered_map<int,int> ump;
     for(int i=0;i<n;i++)
       ump[level[i]]=i;
    return buildTree(in,0,n-1,ump);
    
 }
int main()
{
	int inorder[] = { 4, 2, 5, 1, 6, 3, 7 };
	int level[]   = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(inorder)/sizeof(inorder[0]);
	Node* root = buildTree(inorder, level, n);
	cout << "Inorder traversal of the constructed tree:\n";
	inorderTraversal(root);
	return 0;
}