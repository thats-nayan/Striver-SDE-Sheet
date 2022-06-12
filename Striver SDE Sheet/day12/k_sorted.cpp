
// Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally

// Method 
// Naive Method Sort the array                  O(nlogn)
// Use priority queue of k elements                O(nlogk)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void k_sorted(int a[],int N,int k)
{
    int j = 0;
    priority_queue <int,vector <int>,greater <int>> pq;
    for (int i = 0; i <= k; i++)
    pq.push(a[i]);
    for (int i = k+1; i < N; i++)
    {
        a[j++] = pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    while(pq.empty() == false)
    {
        a[j++] = pq.top();
        pq.pop();
    }
}
int main()
{
    int N,k;
    cin>>N>>k;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    k_sorted(a,N,k);
    for (int i = 0; i < N; i++)
    cout<<a[i]<<" ";
    return 0;
}