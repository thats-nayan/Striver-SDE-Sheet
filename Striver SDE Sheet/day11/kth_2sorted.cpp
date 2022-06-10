
// Same as Finding median of 2 Sorted arrays but a generalised version of that 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ksorted(int a[],int b[],int n,int m,int k)
{
    int low = 0,mid;
    int high = min(n,k);
    while(low <= high)
    {
        mid = (low+high)/2;
        int x = k-mid;
        int l1,l2,r1,r2;
        if(x > m)
        {
            mid += (x-m);
            x = m;
        }
        if(mid <= 0)
        l1 = INT32_MIN;
        else
        l1 = a[mid-1];
        if(x <= 0)
        l2 = INT32_MIN;
        else
        l2 = b[x-1];
        if(mid >= n)
        r1 = INT32_MAX;
        else
        r1 = a[mid];
        if(x >= m)
        r2 = INT32_MAX;
        else
        r2 = b[x];
        // cout<<"l = "<<low<<" mid = "<<mid<<" r = "<<high<<" x = "<<x<<"\n";
        // cout<<"l1 = "<<l1<<" l2 = "<<l2<<" r1 = "<<r1<<" r2 = "<<r2<<"\n";
        if(l1 <= r2 && l2 <= r1)
        return max(l1,l2);
        else if(l2 > r1)
        low = mid+1;
        else
        high = mid-1;
    }
    return -1;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[n],b[m];
    for (int i = 0; i < n; i++)
    cin>>a[i];
    for (int i = 0; i < m; i++)
    cin>>b[i];
    cout<<ksorted(a,b,n,m,k);
    return 0;
}