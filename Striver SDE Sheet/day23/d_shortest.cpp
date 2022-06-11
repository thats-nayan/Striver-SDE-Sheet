
                     // Shortest path in Unweighted Directed Acyclic Graph 

// For weighted graph we use vector <pair<int,int>> 
// Store vertex in topological sort order 
// Pick a vertex from topo sort and update minimum distnaces of all vertex connected to this vertex and repeat the same for other vertex in topological sort array 
// Intuition 
// Vertex having indegree x point to vetex of higher indegree 
// Since vertex are stored in order of topological sort then we get minimum distnace of all vertex in order of topological sort and there is no need to update vertex connected to given vertex which is the case if we do normal BFS ro traverse
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <pair<int,int>> adj[],int x,int y,int W)
{
    adj[x].push_back({y,W});
}
void shortest_path(vector <pair<int,int>> adj[],int V,int s)
{
    int indegree[V];
    for (int i = 0; i < V; i++)
    indegree[i] = 0;
    for (int i = 0; i < V; i++)
    {
        for(auto x: adj[i])
        indegree[x.first]++;
    }
    vector <int> top;
    queue <int> q;
    for (int i = 0; i < V; i++)
    if(indegree[i] == 0)
    q.push(i);
    while(q.empty() == false)
    {
        int p = q.front();
        top.push_back(p);
        q.pop();
        for(auto x: adj[p])
        {
            indegree[x.first]--;
            if(indegree[x.first] == 0)
            q.push(x.first);
        }
    }
    int dis[V];
    for (int i = 0; i < V; i++)
    dis[i] = INT32_MAX;
    dis[s] = 0;
    for (int i = 0; i < V; i++)
    {
        if(dis[top[i]] > 1000)
        continue;
        for(auto x: adj[top[i]])
        dis[x.first] = min(dis[x.first],dis[top[i]]+x.second);
    }
    for (int i = 0; i < V; i++)
    {
        if(dis[i] > 1000)
        cout<<"I ";
        else
        cout<<dis[i]<<" ";
    }
}
int main()
{
    int V,E,x,y,W;
    cin>>V>>E;
    vector <pair<int,int>> adj[V];
    while(E--)
    {
        cin>>x>>y>>W;
        addEdge(adj,x,y,W);
    }
    int s;
    cin>>s;
    shortest_path(adj,V,s);
    return 0;
}