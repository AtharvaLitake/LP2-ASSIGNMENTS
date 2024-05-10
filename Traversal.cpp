#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    map<string,vector<string>>adj;
    
    //to add edge
    void addedge(string computer1,string computer2)
    {
        adj[computer1].push_back(computer2);
        adj[computer2].push_back(computer1);
    }
    void printgraph()
    {
        cout<<endl;
        cout<<"PRINTING GRAPH--"<<endl;
        for(auto computer:adj)
        {
            cout<<computer.first<<" --> ";
            for(auto it: computer.second)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
    void BFS_Traversal(string src)
    {
        vector<pair<string,int>>traversal;
        set<string>visited;
        queue<pair<string,int>>q;
        visited.insert(src);
        q.push({src,0});
        BFS(q,visited,traversal);
        printTraversal("BFS",traversal);
    }
    void BFS(queue<pair<string,int>>&q,set<string>&visited,vector<pair<string,int>>&traversal)
    {
        if(q.empty())
        {
            return;
        }
        pair<string,int>computer=q.front();
        q.pop();
        traversal.push_back(computer);
        for(auto neighbour:adj[computer.first])
        {
            if(visited.find(neighbour)==visited.end())
            {
                visited.insert(computer.first);
                q.push({neighbour,computer.second+1});
            }
        }
        BFS(q,visited,traversal);
    }
    void DFS_Traversal(string src)
    {
        set<string>visited;
        vector<pair<string,int>>traversal;
        DFS(src,0,visited,traversal);
        printTraversal("DFS",traversal);
    }
    void DFS(string src,int level,set<string> &visited,vector<pair<string,int>> &traversal)
    {
        traversal.push_back({src,level});
        visited.insert(src);
        for(auto neighbour:adj[src])
        {
            if(visited.find(neighbour)==visited.end())
            {
                DFS(neighbour,level+1,visited,traversal);
            }
        }
    }
    void printTraversal(string name,vector<pair<string,int>>&traversal)
    {
        cout<<name<<" Traversal --> ";
        for(auto computer:traversal)
        {
            cout<<" ( "<<computer.first<<", "<<computer.second<<" ) ";
        }
    }
};
int main()
{
    Graph g;
    string computer1,computer2;
    int a;
    cout<<"1.Adding Edge\n2.BFS\n3.DFS\n4.Printing\n5.END\n";
    while(true)
    {
        cout<<"Enter Value-->"<<endl;
        cin>>a;
     if(a==1)
     {
         cout<<"Enter Computer 1-->"<<endl;
         cin>>computer1;
         cout<<"Enter Computer 2-->"<<endl;
         cin>>computer2;
         g.addedge(computer1,computer2);
     }
     if(a==2)
     {
         cout<<"Enter Source"<<endl;
         string src;
         cin>>src;
         g.BFS_Traversal(src);
     }
     if(a==3)
     {
         cout<<"Enter Source"<<endl;
         string src;
         cin>>src;
         g.DFS_Traversal(src);
     }
     if(a==4)
     {
         g.printgraph();
     }
     if(a==5)
     {
         break;
     }
    }
}