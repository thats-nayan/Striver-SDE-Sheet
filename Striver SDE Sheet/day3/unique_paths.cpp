
                    // Unique paths in grid 

// Brute Force      
// Use Recursion                    Time O(2^max(n,m))                  Space O(stack space)
// Efficient Method Use Dp Tabulation method 
// Time O(n*m)                 Space o(n*m) 

// Most efficient Method 
// Count ways using P&C 
// Time O(n-1) or O(m-1)                        Space O(1)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Dp Method 
// int paths(int n,int m)
// {
//     long long dp[n][m];
//     for (int i = 0; i < n; i++)
//     dp[i][0] = 1;
//     for (int j = 0; j < m; j++)
//     dp[0][j] = 1;
//     for (int i = 1; i < n; i++)
//     for (int j = 1; j < m; j++)
//     dp[i][j] = dp[i-1][j] + dp[i][j-1];
//     return dp[n-1][m-1];
// }
// P & C Method   ans = nCr where n is M+N-2 and r is n-1 
int paths(int n,int m)
{
    int N = n+m-2;
    int r = n-1;
    double res = 1;
    for (int i = 1; i <= r; i++)
    res = (res * (N-r+i))/i;
    return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<paths(n,m)<<"\n";
    return 0;
}