
                            // Longest SubArray with Zero Sum 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force 
// Traverse all subarrays and compue sum and compare 

// Efficient method 
// Use Hahsmap to store prefix sum and comapre value to get length of subbarray 
int zero_subarray(vector <int> &a,int N)
{
    int sum = 0;
    unordered_map <int,int> m;
    int ans = 0;
    m[0] = -1;
    for (int i = 0; i < N; i++)
    {
        sum += a[i];
        if(m.find(sum) != m.end())
        ans = max(ans,i-m[sum]);
        else
        m[sum] = i;
    }
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector <int> v(N);
    for (int i = 0; i < N; i++)
    cin>>v[i];
    cout<<zero_subarray(v,N)<<"\n";
    return 0;
}