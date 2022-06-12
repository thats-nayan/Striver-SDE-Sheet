
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force 
// Traverse 2D vector and put all elements in an auxiliary array Sort that array and return 
// Time O(n*k*log(n*k))     

// Efficient Method 
// Do the same method as Merge 2 sorted arrays 
// but here maintain a min heap of k elements  Put all arrays starting elements in minheap 
// Pop an element add it to ans aray and increse the index of corresponding array and add next element
// Time O(n*k*log(k))                       Space O(k) 
vector <int> merge_ksorted(vector <vector<int>> &v,int k)
{
    priority_queue <vector<int>,vector <vector<int>>,greater <vector<int>>> pq;
    for (int i = 0; i < k; i++)
    pq.push({v[i][0],0,i});
    vector <int> ans;
    while(pq.empty() == false)
    {
        vector <int> p = pq.top();
        pq.pop();
        ans.push_back(p[0]);
        p[1]++;
        if(p[1] < v[p[2]].size())
        pq.push({v[p[2]][p[1]],p[1],p[2]});
    }
    return ans;
}
int main()
{
    int K,N;
    cin>>K;
    vector <vector<int>> v;
    for (int i = 0; i < K; i++)
    {
        cin>>N;
        vector <int> temp(N);
        for (int i = 0; i < N; i++)
        cin>>temp[i];
        v.push_back(temp);
    }
    vector <int> ans = merge_ksorted(v,K);
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}