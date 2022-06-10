
                    // Fractional Knapsack 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct Item
{
    int value;
    int weight;
}Item;
bool mycomp(Item a,Item b)
{
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    return r1 > r2;
}
double fractional(int N,int W,Item arr[])
{
    sort(arr,arr+N,mycomp);
    double ans = 0;
    for (int i = 0; i < N; i++)
    {
        if(W >= arr[i].weight)
        {
            ans += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            double r1 = (double)arr[i].value/(double)arr[i].weight;
            ans += r1*W;
            W = 0;
        }
        // cout<<"ans = "<<ans<<" W = "<<W<<"\n";
    }
    return ans;
}
int main()
{
    int N,W;
    cin>>N>>W;
    Item arr[N];
    for (int i = 0; i < N; i++)
    cin>>arr[i].value;
    for (int i = 0; i < N; i++)
    cin>>arr[i].weight;
    cout<<fractional(N,W,arr);
    return 0;
}