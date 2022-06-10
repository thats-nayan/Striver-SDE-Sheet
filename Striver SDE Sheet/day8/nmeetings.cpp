
                    // N Meetings in One Room 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int max_meetings(int start[],int end[],int N)
// {
//     pair <int,int> p[N];
//     for (int i = 0; i < N; i++)
//     {
//         p[i].first = start[i];
//         p[i].second = end[i];
//     }
//     sort(p,p+N);
//     int ans = 1;
//     int end_time = p[0].second;
//     for (int i = 1; i < N; i++)
//     {
//         if(p[i].first > end_time)
//         {
//             ans++;
//             end_time = p[i].second;
//         }
//         else
//         end_time = min(end_time,p[i].second);
//     }
//     return ans;
// }
bool mycomp(pair <int,int> p1,pair <int,int> p2)
{
    return p1.second < p2.second;
}
int max_meetings(int start[],int end[],int N)
{
    pair <int,int> p[N];
    for (int i = 0; i < N; i++)
    {
        p[i].first = start[i];
        p[i].second = end[i];
    }
    sort(p,p+N,mycomp);
    int ans = 1;
    int end_time = p[0].second;
    for (int i = 1; i < N; i++)
    {
        if(p[i].first > end_time)
        {
            ans++;
            end_time = p[i].second;
        }
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
    cout<<max_meetings(start,end,N);
    return 0;
}