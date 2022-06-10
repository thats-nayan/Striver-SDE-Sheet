

// Do BFS or DFS on a grid and count number of discontinuos parts
// To reduce space update 1 to 0 in matrix after traversing it
// Time O(V+E)                     Space O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addEdge(int x, int y, vector<int> adj[])
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void BFS(vector<vector<char>> &v, int a, int b)
{
    int N = v.size();
    int M = v[0].size();
    queue<pair<int, int>> q;
    v[a][b] = '0';
    q.push({a, b});
    while (q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < N && x + dx[i] >= 0 && y + dy[i] >= 0 && y + dy[i] < M && v[x + dx[i]][y + dy[i]] == '1')
            {
                q.push({x + dx[i], y + dy[i]});
                v[x + dx[i]][y + dy[i]] = '0';
            }
        }
    }
}
void DFS(vector<vector<char>> &v, int x, int y, int N, int M)
{
    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] < N && x + dx[i] >= 0 && y + dy[i] >= 0 && y + dy[i] < M && v[x + dx[i]][y + dy[i]] == '1')
        {
            v[x + dx[i]][y + dy[i]] = '0';
            DFS(v,x+dx[i],y+dy[i],N,M);
        }
    }
}
int islands(vector<vector<char>> &v)
{
    int N = v.size();
    int M = v[0].size();
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (v[i][j] == '1')
            {
                v[i][j] = '0';
                // BFS(v,i,j);
                DFS(v, i, j, N, M);
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> v(N, vector<char>(M, ' '));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> v[i][j];
    cout << islands(v) << "\n";
    return 0;
}