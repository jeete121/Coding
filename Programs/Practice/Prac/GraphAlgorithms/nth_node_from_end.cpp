#include <bits/stdc++.h>
using namespace std;
//Struture of  node
struct Node
{ 
   int data;
   Node *next;
   Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
//function to find the nth
//node from end of linked list
int  NthNodeFromEnd(Node *head,int n)
{
    //if linked list is empty
    //return -1
    if(head==NULL)
       return -1;
    int length=0;
    //node to store the head of
    //the linked list
     Node *temp=head;
     //iterate till end of list 
     //and count no of nodes
     while(temp!=NULL)
      {
           //increment the count
           //of nodes
           length++;
           //move to the next node
            temp=temp->next;
      }
    //if no of nodes in linked
    //list is less than length of linked
    //list return -1
    if(length<n)
       return -1;
    else
    {
        //n from start
        n=length-n+1;
        temp=head;
        int count =0;
        while(temp!=NULL)
          {
              //increment the count 
              //the node
              count++;
              //if count is same as
              //n return the node data
              if(count==n)
                 return temp->data;
              //move to the next node
              temp=temp->next;
          }
        //if length is less than n return -1
        return -1;
          
    }
}
int main()
{
  Node *head=new Node(5);
  head->next=new Node(2);
  head->next->next=new Node(8);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(1);
  int n=2;
  int nthNode=NthNodeFromEnd(head,n);
  if(nthNode==-1)
    cout<<"Nth node is not present\n";
  else
    cout<<"Nth node is "<<nthNode<<"\n"; 
  return 0;
}
//Time Complexity: O(n)
//Space Complexity:O(1)