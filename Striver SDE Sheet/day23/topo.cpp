
// Topological Sort 
// It is defined only for directed acyclic graph 
// Linear Ordering of vertex such that for any edge u->v which appears in graph , u appers before v in the order 

//  DFS Based Algo for Topo Sort 
// Approach 
// Do DFS for a node then do DFS of the nodes dependancies . after dfs of a node is done put it in stack
// This ensures that dependancies of a node are always below the node in a stack 
// When we empty such a stack in a vector then all nodes will occur before its dependancies 


//  Detect Cycle in Directed Graph 

// DFS Approach 
// There exists a cycle if there is back edge in graph 
// Back edge is edge which connects 2 vertex which are present in same recursion stack 
// Time O(V+E)                                 Space O(V+E) 

// BFS Approach (Kahns Based Algo)
// Create indegree array where indegree of a vertex is no of vertex pointing towards a given vertex
// Then put all elements wityh indegree 0 in queue and do Normal BFS 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(int x,int y,vector <int> adj[])
{
    adj[x].push_back(y);
    // adj[y].push_back(x);
}
void DFS(vector <int> adj[],bool visited[],int i,vector <int> &ans)
{
    for(auto x: adj[i])
    {
        if(visited[x] == false){
        visited[x] = true;
        DFS(adj,visited,x,ans);}
    }
    ans.push_back(i);
}
vector <int> topo_sort(vector <int> adj[],int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    visited[i] = false;
    vector <int> ans;
    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            DFS(adj,visited,i,ans);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector <int> BFS(vector <int> adj[],int V)
{
    int indegree[V] = {0};
    for(int i = 0 ; i < V ; i++)
    {
        for(auto x: adj[i])
        indegree[x]++;
    }
    queue <int> q;
    for(int i = 0 ; i < V ; i++)
    if(indegree[i] == 0)
    q.push(i);
    vector <int> ans;
    while(q.empty() == false)
    {
        int p = q.front();
        q.pop();
        ans.push_back(p);
        for(auto x: adj[p])
        {
            indegree[x]--;
            if(indegree[x] == 0)
            q.push(x);
        }
    }
    return ans;
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
    vector <int> ans = topo_sort(adj,V);
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}