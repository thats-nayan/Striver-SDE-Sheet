
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Similar to merge function of merge sort 
int min_platforms(int start[],int end[],int N)
{
    sort(start,start+N);
    sort(end,end+N);
    int ans = 0;
    int i = 0,j = 0;
    int sum = 0;
    while(i < N)
    {
        if(start[i] <= end[j])
        {
            sum++;
            i++;
        }
        else
        {
            sum--;
            j++;
        }
        ans = max(ans,sum);
    }
    return ans;
}
int main()
{
    int N;
    cin>>N;
    int start[N],end[N];
    for (int i = 0; i < N; i++)
    cin>>start[i];
    for (int i = 0; i < N; i++)
    cin>>end[i];
    cout<<min_platforms(start,end,N);
    return 0;
}