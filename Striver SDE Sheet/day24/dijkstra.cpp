
//          Shortest Path in Weighted Undirected Graph

// If graph is unweighted we can find using queue (BFS)
// If graph is weighted we use dijkstra algorithm 
// Also works for directed graph too 

// Intuition
// If  A->B->C->D is shortest path from A to D then C to D is shortest path from C to D ands B to D is shortest path from B to D and vice versa 
// So at each step we can pick the minimum value 

// Method 
// Make distance array and initislaise everything as infinity 
// Use min priority queue
// Time O((V+E)*logV)                   Soace O(V)  
// Assumptions 
// Weights are all positive
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// void dijkstra(int V,vector <pair<int,int>> adj[],int s)
// {
//     int dis[V+1];
//     for (int i = 0; i <= V; i++)
//     dis[i] = INT32_MAX;
//     dis[s] = 0;
    // priority_queue <pair<int,int>,vector <pair<int,int>>,greater <pair<int,int>>> pq;
    // pq.push({0,s});
    // while (pq.empty()==false)
    // {
    //     pair <int,int> p = pq.top();
    //     pq.pop();
    //     for(auto x: adj[p.second])
    //     {
    //         if(dis[x.first] > p.first+x.second)
    //         {
    //             dis[x.first] = p.first+x.second;
    //             pq.push({dis[x.first],x.first});
    //         }
    //     }
    // }
//     for (int i = 0; i <= V; i++)
//     cout<<dis[i]<<" ";
// }
// int main()
// {
//     int V,E,x,y,W;
//     cin>>V>>E;
//     vector <pair<int,int>> adj[V+1];
//     while(E--)
//     {
//         cin>>x>>y>>W;
//         adj[x].push_back({y,W});
//         adj[y].push_back({x,W});
//     }
//     int s;
//     cin>>s;
//     dijkstra(V,adj,s);
//     return 0;
// }

                        // Minimum Cost path 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int min_cost(vector <vector<int>> &v)
{
    int N = v.size();
    priority_queue <vector <int>,vector <vector <int>>,greater <vector <int>>> pq;
    vector <vector<int>> dis(N,vector <int> (N,INT32_MAX));
    pq.push({v[0][0],0,0});
    dis[0][0] = v[0][0];
    while(pq.empty() == false)
    {
        int x = pq.top()[0];
        int i = pq.top()[1];
        int j = pq.top()[2];
        pq.pop();
        if(i+1 < N && dis[i+1][j] > x+v[i+1][j])
        {
            dis[i+1][j] = x + v[i+1][j];
            pq.push({dis[i+1][j],i+1,j});
        }
        if(j+1 < N && dis[i][j+1] > x+v[i][j+1])
        {
            dis[i][j+1] = x + v[i][j+1];
            pq.push({dis[i][j+1],i,j+1});
        }
        if(i-1 > -1 && dis[i-1][j] > x+v[i-1][j])
        {
            dis[i-1][j] = x + v[i-1][j];
            pq.push({dis[i-1][j],i-1,j});
        }
        if(j-1 > -1 && dis[i][j-1] > x+v[i][j-1])
        {
            dis[i][j-1] = x + v[i][j-1];
            pq.push({dis[i][j-1],i,j-1});
        }
    }
    return dis[N-1][N-1];
}
int main()
{
    int N;
    cin>>N;
    vector <vector<int>> v(N,vector <int> (N));
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    cin>>v[i][j];
    cout<<min_cost(v);
    return 0;
}