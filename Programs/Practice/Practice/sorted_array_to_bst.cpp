#include <bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node *left,*right;
    int data;
};
void inorder(struct Node *root)
 {
     if(root==NULL)
         return;
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);

 }
 void preorder(struct Node *root)
 {
     if(root==NULL)
         return;
     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);

 }
struct Node *create(int data)
{
  struct Node *newNode=new Node();
  newNode->data=data;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
}
struct Node * sorted_array_to_bst(int arr[],int start,int end1)
{
  if(start>end1)
      return NULL;
  int mid=start+(end1-start)/2;
  struct Node *root=create(arr[mid]);
  root->left=sorted_array_to_bst(arr,start,mid-1);
  root->right=sorted_array_to_bst(arr,mid+1,end1);
  return root;

}
int main()
{
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
      cin>>arr[i];
 sort(arr,arr+n);
 struct Node *root=sorted_array_to_bst(arr,0,n-1);
 inorder(root);
 cout<<endl;
 preorder(root);
 return 0;
}
