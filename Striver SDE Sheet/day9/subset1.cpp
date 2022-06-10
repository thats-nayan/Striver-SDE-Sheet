                    // Subset Sum 1 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force Method 
// Use Bit Manipultion and generate all subsets 
// Efficient Method 
// Generate all subsets using recursion 
void recursion(vector <int> &v,int i,int sum,int N,vector <int> &ans)
{
    if(i == N)
    ans.push_back(sum);
    else
    {
        recursion(v,i+1,sum,N,ans);
        recursion(v,i+1,sum+v[i],N,ans);
    }
}
vector <int> subset_sum1(vector <int> &v,int N)
{
    vector <int> ans ;
    recursion(v,0,0,N,ans);
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector <int> v(N);
    for (int i = 0; i < N; i++)
    cin>>v[i];
    vector <int> ans = subset_sum1(v,N);
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}