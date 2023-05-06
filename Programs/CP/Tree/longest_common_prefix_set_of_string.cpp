#include <bits/stdc++.h>
using namespace std;
struct Trie
{
  bool isLeaf;
  unordered_map<char,Trie*> character;
  Trie()
   {
       isLeaf=false; 
   }
};
void insert(Trie *const &head,string &str)
{
   Trie *curr=head;
   for(int i=0;i<str.size();i++)
     {
         if(curr->character[str[i]]==nullptr)
           curr->character[str[i]]=new Trie();
         curr=curr->character[str[i]];
     }
     curr->isLeaf=true;
}
string LCP(string dict[],int n)
{
    Trie *head=new Trie();
    for(int i=0;i<n;i++)
      insert(head,dict[i]);
    string lcp;
    Trie *curr=head;
    while((curr && !curr->isLeaf)&&(curr->character.size()==1))
      {
          auto it=curr->character.begin();
          lcp+=it->first;
          curr=it->second;

      }
      return lcp;
}
int main()
{
	string dict[] =
	{
		"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codependence", "codependency", "codependent",
		"codependents", "codes", "codesign", "codesigned", "codeveloped",
		"codeveloper", "codex", "codify", "codiscovered", "codrive","codability"
	};
	 int n = sizeof(dict)/sizeof(dict[0]);
    string res =LCP(dict,n);
    cout<<"Longest Common Prefix is "<<res<<"\n";
    cout<<"Length of Common Prefix is "<<res.size();
	return 0;
}