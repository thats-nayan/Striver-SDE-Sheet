
                    // Shortest Distance in Undirected Unweighted Graph

// Approach 
// Do BFS From Source Vertex and Update distnace i distance array 
// Time O(V+E)                                  Space O(V)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(int x,int y,vector <int> adj[])
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
vector <int> shortest(vector <int> adj[],int V,int s)
{
    vector <int> dis(V,-1);
    queue <int> q;
    q.push(s);
    dis[s] = 0;
    while(q.empty() == false)
    {
        int p = q.front();
        q.pop();
        for(auto x: adj[p])
        {
            if(dis[x] == -1)
            {
                q.push(x);
                dis[x] = dis[p]+1;
            }
        }
    }
    return dis;
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
    int s;
    cin>>s;
    vector <int> ans = shortest(adj,V,s);
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}