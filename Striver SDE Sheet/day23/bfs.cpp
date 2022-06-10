
// BFS (Breadth First Search)
// Visit a node then its neighbours then their neighbours and so on 
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
void BFS_i(vector <int> adj[],bool visited[],int i)
{
    queue <int> q;
    q.push(i);
    visited[i] = true;
    while(q.empty() == false)
    {
        int p = q.front();
        cout<<p<<" ";
        q.pop();
        for(auto x: adj[p])
        {
            if(visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
void BFS(vector <int> adj[],int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    visited[i] = false;
    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        BFS_i(adj,visited,i);
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
    BFS(adj,V);
    return 0;
}