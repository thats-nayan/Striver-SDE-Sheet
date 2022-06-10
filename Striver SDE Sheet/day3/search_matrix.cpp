
// 2 Variations 

// 1) Leetcode
// Rows are sorted in increasing order 
// First element of each row greater than last element of previous row 

// 2) GFG 
// Rows and columns are sorted 

// Brute Force 
// 1) Linear Search element by element 
// Time O(n*m)                                 Space O(1) 
// Brute Force Approach 2 
// do binary search in each row 
// Time O(nlogm)           Space O(1) 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Leetcode
// Efficient Algo 
// Binary Search  Search is similar to searching in sorted array just there are rowd and columns instead
// Row No = mid / no of columns             Column no = mid % no of columns 
// Time O(log(n) + log(m))              Space O(1)
bool search_2D(vector <vector<int>> &v,int x)
{
    int n = v.size();
    int m = v[0].size();
    int l = 0,r = n*m - 1;
    while(l <= r)   
    {
        int mid = (l+r)/2;
        if(v[mid/m][mid%m] == x)
        return true;
        else if(v[mid/m][mid%m] > x)
        r = mid-1;
        else
        l = mid+1;
    }
    return false;
}
// GFG Efficient Method 
// Time O(n+m)                          Space O(1)
bool search__2D(vector <vector<int>> &v,int x)
{
    int n = v.size();
    int m = v[0].size();
    int i = 0,j = m-1;
    while(i >= 0 && j >= 0 && i < n && j < m)
    {
        // cout<<"i = "<<i<<" j = "<<j<<" v = "<<v[i][j]<<"\n";
        if(v[i][j] == x)
        return true;
        else if(v[i][j] > x)
        j--;
        else
        i++;
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector <vector<int>> v(n,vector <int> (m,-1));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    cin>>v[i][j];
    int x;
    cin>>x;
    // cout<<search_2D(v,x);
    cout<<search__2D(v,x);
    return 0;
}