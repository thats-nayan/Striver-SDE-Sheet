
                        // Majority Element (appears more than n/2 times)
                    
// Brute Force 
// 1) Use nested loops to find frequency 
// Time O(N*N)                  Space o(1) 

// 2) Use sorting and count frequency 
// Time O(nlogn)           Space O(1) 

// 3) Use hashing to find frequenchy 
// Time O(n)               Space o(n) 

// 4) Moore Voting Algo 
// Most Efficient 
// Time O(N)               Space o(1) 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int moore(int a[],int N)
{
    int count = 0,res = 0;
    for (int i = 0; i < N; i++)
    {
        if(a[i] == a[res])
        count++;
        else
        count--;
        if(count == 0)
        {
            res = i;
            count = 1;
        }
    }
    return a[res];
    // If it is not sure whee majority element always exist or not then traverse one ore time to count frequency of obtained elemet
    // Best Pratice is to ask interviewer whether majority element always exist or not
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    cout<<moore(a,N)<<"\n";
    return 0;
}