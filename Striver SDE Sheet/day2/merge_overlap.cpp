
// Brute Force Approach 
// Sort and the linearly iterate from all intervals and store merged intervals in another DS 
// Time O(N*N)                 Space O(N) 

// Efficient Approach 
// Sort intervals wrt to starting time and then chec if the interval is merging with last overlapped interval 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector <vector <int>> merge_overlap(vector <vector <int>> &v)
{
    int N = v.size();
    sort(v.begin(),v.end());
    int res = 0;
    for (int i = 1; i < N; i++)
    {
        if(v[i][0] <= v[res][1])
        v[res][1] = max(v[res][1],v[i][1]);
        else
        {
            res++;
            v[res] = v[i];
        }
    }
    vector <vector<int>> ans;
    for (int i = 0; i <= res; i++)
    ans.push_back(v[i]);
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector <vector<int>> v(N,vector<int> (2,-1));
    for (int i = 0; i < N; i++)
    cin>>v[i][0]>>v[i][1];
    vector <vector<int>> ans = merge_overlap(v);
    for(auto x: ans)
    cout<<x[0]<<" "<<x[1]<<"\n";
    return 0;
}