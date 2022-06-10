
                        // Minimum Number of Coins 

// Coins         [1,2,5,10,20,50,100,500,1000]

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int min_coins(int V)
{
    int coins[9] =   {1,2,5,10,20,50,100,500,1000};
    int ans = 0;
    for (int i = 8; i >= 0; i--)
    {
        if(V >= coins[i])
        {
            ans += V/coins[i];
            V %= coins[i];
        }
    }
    return ans;
}
int main()
{
    int V;
    cin>>V;
    cout<<min_coins(V);
    return 0;
}