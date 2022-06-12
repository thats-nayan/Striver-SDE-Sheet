
                    // K Most Frequent Elements 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Naive Method  
// Create vector of <value,frequency> sort it and print last k elemennts        Time O(nlogn)       Space o(n)
// Efficient Method 
// Same as k largest element but here we maintain pair instead of int           Time O(nlogK)       Space O(k) 
vector <int> kfrequent(vector <int> &a,int K)
{
    int N = a.size();
    unordered_map <int,int> m;
    for (int i = 0; i < N; i++)
    m[a[i]]++;
    int i = 0;
    priority_queue <pair<int,int>,vector <pair<int,int>> ,greater <pair<int,int>>> pq;
    for(auto x: m)
    {
        if(i < K)
        pq.push({x.second,x.first});
        else
        {
            if(x.second > pq.top().first)
            {
                pq.pop();
                pq.push({x.second,x.first});
            }
        }
        i++;
    }
    vector <int> ans;
    while(pq.empty() == false)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
int main()
{
    int N,K;
    cin>>N>>K;
    vector <int> a(N);
    for (int i = 0; i < N; i++)
    cin>>a[i];
    vector <int> ans = kfrequent(a,K);
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}