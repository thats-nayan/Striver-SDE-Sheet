
                    // Count SubArrays With Given Xor 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force 
// Run 2 nested loops and find xor of each subarray 
// Efficient Method 
// Use hashing and apply same method as find subarrays with given sum 
// Time O(N)                   Space O(n) 
int subarray_xor(vector <int> &a,int X)
{
    int N = a.size();
    unordered_map <int,int> m;
    m[0]++;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        sum ^= a[i];
        if(m.find(sum^X) != m.end())
        ans += m[sum^X];
        m[sum]++;
    }
    return ans;
}
int main()
{
    int N,X;
    cin>>N>>X;
    vector <int> a(N);
    for (int i = 0; i < N; i++)
    cin>>a[i];
    cout<<subarray_xor(a,X);
    return 0;
}