#include <bits/stdc++.h>
#define CHAR_SIZE 256
using namespace std;
class Trie
{
    public:
      bool isLeaf;
      Trie *character[CHAR_SIZE];
      Trie()
       {
           this->isLeaf=false;
           for(int i=0;i<CHAR_SIZE;i++)
            this->character[i]=nullptr;
       }
       void insert(string);
       bool deletion(Trie *&,string);
       bool search(string);
       bool haveChildren(Trie const *);
};
void Trie::insert(string str)
{
   Trie *curr=this;
   for(int i=0;i<str.length();i++)
     {
         if(curr->character[str[i]]==nullptr)
           curr->character[str[i]]=new Trie();
         curr=curr->character[str[i]];
     }
     curr->isLeaf=true;
}

bool Trie::search(string str)
{
    if(this==nullptr)
       return false;
    Trie *curr=this;
    for(int i=0;i<str.length();i++)
       {
           curr=curr->character[str[i]];
           if(curr==nullptr)
              return false;
       }
    return curr->isLeaf;
}
bool Trie::haveChildren(Trie const* curr)
{
   for(int i=0;i<CHAR_SIZE;i++)
      if(curr->character[i])
        return true;
    return false;
}
bool Trie::deletion(Trie *& curr,string str)
{
    if(curr==nullptr)
       return false;
    if(str.length())
    {
   	if (curr != nullptr &&
			curr->character[str[0]] != nullptr &&
			deletion(curr->character[str[0]], str.substr(1)) &&
			curr->isLeaf == false)
      {
          if(!haveChildren(curr))
             {
              delete curr;
              curr=nullptr;
              return true;   
             }
            else
             return false;
      }
    }
    if(str.length()==0 &&curr->isLeaf)
    {
         if(!haveChildren(curr))
             {
              delete curr;
              curr=nullptr;
              return true;   
             }
          else
          {
            curr->isLeaf=false;
             return false;
          }
    }
    return false;
}
int main()
{
	Trie* head = new Trie();
	head->insert("hello");
	cout << head->search("hello") << " ";
	head->insert("helloworld");
	cout << head->search("helloworld") << " ";
	cout << head->search("helll") << " ";
	head->insert("hell");
	cout << head->search("hell") << " "; 
	head->insert("h");
	cout << head->search("h");
    cout <<endl;
	head->deletion(head, "hello");
	cout << head->search("hello") << " ";  
	cout << head->search("helloworld") << " "; 
	cout << head->search("hell");
	cout << std::endl;
	head->deletion(head, "h");
	cout << head->search("h") << " ";  		
	cout << head->search("hell") << " ";   	
	cout << head->search("helloworld");		
    cout << std::endl;
	head->deletion(head, "helloworld");
	cout << head->search("helloworld") << " "; 
	cout << head->search("hell") << " ";
	head->deletion(head, "hell");
	cout << head->search("hell");  		
    cout<<endl;
	if (head == nullptr)
		cout << "Trie empty!!\n";
	cout << head->search("hell");
	return 0;
}