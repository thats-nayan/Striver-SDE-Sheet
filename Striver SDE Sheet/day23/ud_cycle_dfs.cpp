
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Approach 
// Do Normal DFS traversal . Maintain a pair of (Node,parent) while traversing and if a node is already been visited then comapre it with parent to check whether there is cycle or not 
// Time O(V+E)                                 Space O(V+E) 
void addEdge(int x,int y,vector <int> adj[])
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
bool DFS(vector <int> adj[],bool visited[],int s,int p)
{
    for(auto x: adj[s])
    {
        if(visited[x] && x != p)
        return true;
        else if(visited[x] == false)
        {
            visited[x] = true;
            if(DFS(adj,visited,x,s))
            return true;
        }
    }
    return false;
}
bool detect_cycle2(vector <int> adj[],int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    visited[i] = false;
    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            if(DFS(adj,visited,i,-1))
            return true;
        }
    }
    return false;
}
int main()
{
    int x,y,V,E;
    cin>>V>>E;
    vector <int> adj[V];
    while(E--)
    {
        cin>>x>>y;
        addEdge(x,y,adj);
    }
    cout<<detect_cycle2(adj,V);
    return 0;
}