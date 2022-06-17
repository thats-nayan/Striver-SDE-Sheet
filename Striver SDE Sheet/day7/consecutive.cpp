
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int max_ones(int a[],int N)
{
    int sum = 1;
    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        if(a[i] == a[i-1])
        sum++;
        else
        {
            if(a[i-1] == 1)
            ans = max(ans,sum);
            sum = 1;
        }
    }
    if(a[N-1] == 1)
    ans = max(ans,sum);
    return ans;
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    cout<<max_ones(a,N);
    return 0;
}