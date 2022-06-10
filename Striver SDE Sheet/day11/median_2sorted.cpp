
                            // Median Of 2 Sorted Arrays 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Naive Method                   
// Create extra array of length M+N and do merge process of merge sort and return middle element 
// Time O(n+M)                 Space O(N+M) 
// Efficent Method  Use Bianry Search 
double median(vector <int> &a,vector <int> &b)
{
    int n = a.size();
    int m = b.size();
    if(m > n)
    return median(b,a);
    int l = 0,r = (n+m)/2;
    while(l <= r)
    {
        int mid = (l+r)/2;
        int x = (n+m)/2 - mid;
        int l1,l2,r1,r2;
        // Edge case to avoid runtime error
        if(x > m)
        {
            mid += (x-m);
            x = m;
        }
        if(mid == 0)
        l1 = INT32_MIN;
        else
        l1 = a[mid-1];
        if(x == 0)
        l2 = INT32_MIN;
        else
        l2 = b[x-1];
        if(mid < n)
        r1 = a[mid];
        else
        r1 = INT32_MAX;
        if(x < m)
        r2 = b[x];
        else
        r2 = INT32_MAX;
        // cout<<"l1 = "<<l1<<" l2 = "<<l2<<" r1 = "<<r1<<" r2 = "<<r2<<"\n";
        // cout<<"l = "<<l<<" r = "<<r<<" mid = "<<mid<<"\n";
        if(l1 <= r2 && l2 <= r1)
        {
            if((m+n)%2 == 0)
            return (max(l1,l2)+min(r1,r2))/2.0;
            else
            return min(r1,r2);
        }
        else if(l2 > r1)
        l = mid+1;
        else
        r = mid-1;
    }
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector <int> a(N);
    vector <int> b(M);
    for (int i = 0; i < N; i++)
    cin>>a[i];
    for (int i = 0; i < M; i++)
    cin>>b[i];
    cout<<median(a,b)<<"\n";
    return 0;
}