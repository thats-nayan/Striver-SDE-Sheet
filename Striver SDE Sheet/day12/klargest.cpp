
                    // K largest Elements in Array 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Print k largest elements in array 
// Naive Method 
// Sort the Array and Print last k elements                 Time O(nlogn)

// Efficient Method                                     Time O(NlogK) 
// Create min priority queue of k elements 
// Then traverse last n-k elements if a[i] > pq.top() then insert that in minheap and remove pq.top 
// By doing this at any index i > k we have k largest elements from {0,i}

// Similarly for k smallest elements we create max priority queue
void k_largest(vector <int> &a,int N,int K)
{
    priority_queue <int,vector <int> ,greater <int>> pq;
    for (int i = 0; i < K; i++)
    pq.push(a[i]);
    for (int i = K; i < N; i++)
    {
        if(a[i] > pq.top())   
        {
            pq.push(a[i]);
            pq.pop();
        }
    }
    while(pq.empty() == false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main()
{
    int N,K;
    cin>>N>>K;
    vector <int> a(N);
    for (int i = 0; i < N; i++)
    cin>>a[i];
    k_largest(a,N,K);
    return 0;
}