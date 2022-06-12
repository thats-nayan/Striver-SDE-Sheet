
                            // Find Median in a Stream

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force          O(N*N)                          Space O(1)
// Sort the array using insertion sort and output median 

// Efficient method 
// Create a minheap 
// store max n/2 elements in minheap 
// Create maxheap 
// store min n/2 elements in maxheap
// If number of elements is odd then retuen topmost element of maxheap 
// else ans = average of topmost elements of both heaps  
vector <double> median(int a[],int N)
{
    priority_queue <int> pq1;
    priority_queue <int,vector <int>,greater <int>> pq2;
    vector <double> ans;
    for (int i = 0; i < N; i++)
    {
        if(i&1)
        {
            if(a[i] >= pq1.top())
            pq2.push(a[i]);
            else
            {
                pq1.push(a[i]);
                pq2.push(pq1.top());
                pq1.pop();
            }
            double x = (pq1.top()+pq2.top())/2.0;
            ans.push_back(x);
        }
        else
        {
            if(pq2.empty() || a[i] <= pq2.top())
            pq1.push(a[i]);
            else
            {
                pq2.push(a[i]);
                pq1.push(pq2.top());
                pq2.pop();
            }
            ans.push_back(pq1.top());
        }
    }
    return ans;
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    vector <double> ans = median(a,N);
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}