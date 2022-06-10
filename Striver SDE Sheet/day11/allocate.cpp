
                        // Aloocate Minimum Pages 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Answer always lies between max element of arra and sum of all elements so we can apply binary search between them
// Time O(log2(sum - max(a)))                           Space O(1)
int min_time(int a[],int N,int M)
{
    int l = -1,r = 0;
    for (int i = 0; i < M; i++)
    {
        l = max(l,a[i]);
        r += a[i];
    }
    int m;
    int ans;
    while(l <= r)
    {
        m = (l+r)/2;
        int k = 1,sum = 0;
        for (int i = 0; i < M; i++)
        {
            if(sum + a[i] > m)
            {
                k++;
                sum = a[i];
            }
            else
            sum += a[i];
        }
        if(k <= N)
        {
            ans = m;
            r = m-1;
        }
        else
        l = m+1;
    }
    return ans;
}
int main()
{
    int N,M;
    cin>>N>>M;
    int a[M];
    for (int i = 0; i < M; i++)
    cin>>a[i];
    cout<<min_time(a,N,M);
    return 0;
}