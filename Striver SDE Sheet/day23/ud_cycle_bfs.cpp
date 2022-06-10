
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Approach 
// Do Normal BFS traversal . Maintain a pair of (Node,parent) while traversing and if a node is already been visited then comapre it with parent to check whether there is cycle or not 
// Time O(V+E)                                 Space O(V+E) 
void addEdge(int x,int y,vector <int> adj[])
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
bool BFS(vector <int> adj[],int s,bool visited[])
{
    queue <pair<int,int>> q;
    visited[s] = true;
    q.push({s,-1});
    while(q.empty() == false)
    {
        pair <int,int> p = q.front();
        q.pop();
        for(auto x: adj[p.first])
        {
            if(visited[x] == false)
            {
                visited[x] = true;
                q.push({x,p.first});
            }
            else if(x != p.second)
            return true;
        }
    }
    return false;
}
bool detect_cycle1(vector <int> adj[],int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    visited[i] = false;
    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        {
            if(BFS(adj,i,visited))
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
    cout<<detect_cycle1(adj,V);
    return 0;
}