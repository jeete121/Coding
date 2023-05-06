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
//function to find the nth node from
//beginning in linked list
int nthNodeFromBeginning(Node *head,int n)
{
    //if linked list is empty
    //return -1
    if(head==NULL)
       return -1;
    //node to store the head of
    //the linked list
     Node *temp=head;
     //varible to hold the count of nodes
     int count=0;
     //iterate till end of list or
     //count becomes n
     while(temp!=NULL)
      {
          //increment the count
          //of nodes
          count++;
          //if count becomes n then
          //return the current node data
          if(count==n)
            return temp->data;
        //move to the next node
          else
            temp=temp->next;
      }
    //if length of linked list 
    //is less than n then return -1
     return -1;
}
int main()
{
  Node *head=new Node(5);
  head->next=new Node(2);
  head->next->next=new Node(8);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(1);
  int n=2;
  int nthNode=nthNodeFromBeginning(head,n);
  if(nthNode==-1)
      cout<<"Nth node is not present \n";
   else
     cout<<"Nth node is "<<nthNode<<"\n";
  return 0;
}
//Time Complexity: O(n)
//Space Complexity:O(1)