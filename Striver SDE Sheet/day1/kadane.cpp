
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// 1) Brute Force Approach                      Time O(n*n) 
// Iterate over all subarrays and find maximum sum 
// 2) Efficient Approach                        Time O(N)
// Use Kadane Algo 
int max_sum(int a[],int N)
{
    int MAX = a[0];
    int res = a[0];
    for (int i = 1; i < N; i++)
    {
        MAX = max(MAX+a[i],a[i]);
        res = max(res,MAX);
    }
    return res;
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    cout<<max_sum(a,N);
    return 0;
}