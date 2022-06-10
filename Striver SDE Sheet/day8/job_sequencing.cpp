
                        // Job Sequencing 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Efficient Method                     Time O(nlogn + m*n) where m is max time         Space o(m)
// Using disjoint set union we can optimise time complexity to Time O(nlogn)
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
bool mycomp(Job a,Job b)
{
    return a.profit > b.profit;
}
int max_profit(Job arr[],int n)
{
    sort(arr,arr+n,mycomp);
    int MAX = -1;
    for (int i = 0; i < n; i++)
    MAX = max(MAX,arr[i].dead);
    int time[MAX+1];
    for (int i = 0; i <= MAX; i++)
    time[i] = -1;
    time[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i].dead;
        while(temp > 0 && time[temp] != -1)
        temp--;
        if(temp > 0)
        {
            ans += arr[i].profit;
            time[temp] = arr[i].profit;
        }
    }
    return ans;
}
int main()
{
    int N;
    cin>>N;
    Job arr[N];
    for (int i = 0; i < N; i++)
    cin>>arr[i].id>>arr[i].dead>>arr[i].profit;
    cout<<max_profit(arr,N);
    return 0;
}