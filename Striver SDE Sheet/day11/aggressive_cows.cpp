
                        // Aggressive Cows 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Time O(log2(MAX-MIN))                        Space O(1)   
// Binary search for each value of minimum distance       
int aggressive(int a[],int N,int C)
{
    sort(a,a+N);
    int l = 1,r = a[N-1]-a[0];
    int ans;
    while(l <= r)
    {   
        int m = (l+r)/2;
        int start = a[0];
        int k = 1;
        for (int i = 1; i < N; i++)
        {
            if(a[i]-start >= m)   
            {
                k++;
                start = a[i];
            }
        }
        // cout<<"l = "<<l<<" r = "<<r<<" m = "<<m<<" k = "<<k<<"\n";
        if(k >= C)
        {
            ans = m;
            l = m+1;
        }
        else
        r = m-1;
    }
    return ans;
}
int main()
{
    int N,C;
    cin>>N>>C;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    cout<<aggressive(a,N,C);
    return 0;
}