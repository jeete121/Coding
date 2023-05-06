#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
    unordered_map<T,list<pair<T,T>>> m;
public:
    void build_graph(T u,T v,T d)
    {
        m[u].push_back(make_pair(v,d));
    }

    void print_DFA()
    {   cout<<"--------DFA-------\n"<<endl;
        cout<<"q0"<<"-->";
        for(auto j:m["q0"])
            cout<<"("<<j.first<<","<<j.second<<") ";
        cout<<endl;
        cout<<"q1"<<"-->";
        for(auto j:m["q1"])
            cout<<"("<<j.first<<","<<j.second<<") ";
        cout<<endl;
        cout<<"qf"<<"-->";
        for(auto j:m["qf"])
            cout<<"("<<j.first<<","<<j.second<<") ";
        cout<<endl;
        cout<<"fi"<<"-->";
        for(auto j:m["fi"])
            cout<<"("<<j.first<<","<<j.second<<") ";
        cout<<endl;
    }
    void print_MINI_DFA()
    {
         cout<<"\n\n\n\n-----DFA MINIMIZATION-------\n\n\n"<<endl;
        cout<<"A"<<"-->";
        for(auto j:m["A"])
            cout<<"("<<j.first<<","<<j.second<<") ";
        cout<<endl;
        cout<<"B"<<"-->";
        for(auto j:m["B"])
            cout<<"("<<j.first<<","<<j.second<<") ";
        cout<<endl;
        cout<<"Cf"<<"-->";
        for(auto j:m["Cf"])
        cout<<"("<<j.first<<","<<j.second<<") ";
        cout<<endl;
        cout<<"D"<<"-->";
        for(auto j:m["D"])
            cout<<"("<<j.first<<","<<j.second<<") ";
        cout<<endl;
    }
};
int main()
{
 graph <string> g;
 string str="ab*c";
 g.build_graph("q0","q1","a");
 g.build_graph("q0","fi","b");
 g.build_graph("q0","fi","c");
 g.build_graph("q1","q1","b");
 g.build_graph("q1","qf","c");
 g.build_graph("q1","fi","a");
 g.build_graph("qf","fi","a");
 g.build_graph("qf","fi","b");
 g.build_graph("qf","fi","c");
 g.build_graph("fi","fi","a");
 g.build_graph("fi","fi","b");
 g.build_graph("fi","fi","c");
 g.print_DFA();
 g.build_graph("A","B","a");
 g.build_graph("A","D","b");
 g.build_graph("A","D","c");
 g.build_graph("B","B","b");
 g.build_graph("B","Cf","c");
 g.build_graph("B","D","a");
 g.build_graph("Cf","D","a");
 g.build_graph("Cf","D","b");
 g.build_graph("Cf","D","c");
 g.build_graph("D","D","a");
 g.build_graph("D","D","b");
 g.build_graph("D","D","c");
 g.print_MINI_DFA();
}
