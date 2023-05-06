#include<bits/stdc++.h>
using namespace std;
#define CHAR_SIZE 256
struct Trie
{
  string key;
  Trie* character[CHAR_SIZE];
  Trie()
  { 
      for(int i=0;i<CHAR_SIZE;i++)
         character[i]=nullptr;
  }
};
void insert(Trie* &head, string const &str)
{
	Trie* curr = head;
	for (char ch: str)
	{
		if (curr->character[ch - 'a'] == nullptr)
			curr->character[ch - 'a'] = new Trie();
		curr = curr->character[ch - 'a'];
	}
	curr->key = str;
}
bool preorder(Trie *const curr,Trie const *root)
{
    if(curr==nullptr)
       return false ;
    for(int i=0;i<CHAR_SIZE;i++)
     {
         if(curr->character[i]!=nullptr)
           {
               if(curr->character[i]->key.length()>0)
                  cout<<curr->character[i]->key<<"\n";
               preorder(curr->character[i],root);
           }
     }
   return true;
}
int main()
{
	Trie* head = new Trie();
	string dict[] =
	{
		"lexicographic", "sorting", "of", "a", "set", "of", "keys", "can",
		"be", "accomplished", "with", "a", "simple", "trie", "based",
		"algorithm", "we", "insert", "all", "keys", "in", "a", "trie",
		"output", "all", "keys", "in", "the", "trie", "by", "means", "of",
		"preorder", "traversal", "which", "results", "in", "output", "that",
		"is", "in", "lexicographically", "increasing", "order", "preorder",
		"traversal", "is", "a", "kind", "of", "depth", "first", "traversal"
	};
    int n = sizeof(dict)/sizeof(dict[0]);
	for (int i=0;i<n;i++) 
		insert(head, dict[i]);
	preorder(head, head);
	return 0;
}