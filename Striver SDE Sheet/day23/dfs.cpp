
// DFS (Depth First Search)
// Visit each path in a graph from a given source node
// Time O(V+E)                                         Space O(V+E)  V+e for adjency list V for visited array
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(int x,int y,vector <int> adj[])
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void DFS_rec(vector <int> adj[],int i,bool visited[])
{
    cout<<i<<" ";
    for(auto x: adj[i])
    {
        if(visited[x] == false)
        {
            visited[x] = true;
            DFS_rec(adj,x,visited);
        }
    }
}
void DFS(vector <int> adj[],int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    visited[i] = false;
    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            DFS_rec(adj,i,visited);
        }
    }
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
    DFS(adj,V);
    return 0;
}