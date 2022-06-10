
                        // Search in sorted rotated array 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force 
// Do Linear Search                         Time O(N)                   Space O(1)
// Efficient Approach 
// Do Binary Search                         Time O(logN)                Space O(1)
int search(int a[],int N,int x)
{
    int l = 0,r = N-1,m;
    while(l <= r)
    {
        m = (l+r)/2;
        // cout<<"l = "<<l<<" r = "<<r<<" m = "<<m<<"\n";
        if(a[m] == x)
        return m;
        if(a[m] > a[0])
        {
            if(x >= a[0] && x <= a[m])
            r = m-1;
            else
            l = m+1;
        }
        else
        {
            if(x >= a[m] && x <= a[N-1])
            l = m+1;
            else
            r = m-1;
        }
    }
    return -1;
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    int x;
    cin>>x;
    cout<<search(a,N,x);
    return 0;
}