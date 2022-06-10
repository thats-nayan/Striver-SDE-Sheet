
                        // Repeat and Missing Number 

// Brute Force Approach 1 
// Run 2 nested loops and check                 Time O(n*n)         Space O(1)

// Brute Force Approach 2 
// Use hashmap                              Time O(n)              Space O(n)

// Efficient Approach 1 
// Use xor property 
// Find 2 elements which occurs odd number of times in array variation         
// Time O(N)                    Space O(1)

// Efficient Approach 2     
// Use formula x - y = sum - N*(N-1)/2 
// x*x - y*y = sum(all)*sum(all) - (N*(N+1)*(2*N+1))/6 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Efficient Approach 1 
// void repeat_missing(int a[],int N)
// {
//     int sum = 0;
//     for (int i = 0; i < N; i++)
//     {
//         sum ^= a[i];
//         sum ^= (i+1);
//     }
//     // cout<<"sum = "<<sum<<"\n";
//     int x = sum - (sum&(sum-1));
//     // cout<<"x = "<<x<<"\n";
//     int sum1 = 0,sum2 = 0;
//     for (int i = 0; i < N; i++)
//     {
//         if((a[i]&x) == 0)
//         sum1 ^= a[i];
//         else
//         sum2 ^= a[i];
//         if(((i+1)&x) == 0)
//         sum1 ^= (i+1);
//         else
//         sum2 ^= (i+1);
//     }
//     for (int i = 0; i < N; i++)
//     {
//         if(a[i] == sum1)
//         {
//             cout<<sum1<<" "<<sum2<<"\n";
//             return ;
//         }
//         if(a[i] == sum2)
//         {
//             cout<<sum2<<" "<<sum1<<"\n";
//             return ;
//         }
//     }
// }
// Efficient Approach 2
// Might give erro on big numbers so use evrything in long long
// void repeat_missing(int a[],int N)
// {
//     int sum = 0,sum2 = 0;
//     for (int i = 0; i < N; i++)
//     {
//         sum += a[i];
//         sum2 += a[i]*a[i];
//     }
//     int c = sum - (N*(N+1))/2;
//     int b = sum2 - (N*(N+1)*(2*N+1))/6;
//     b /= c;
//     int x = (b + c)/2;
//     int y = (b-c)/2;
//     cout<<x<<" "<<y<<"\n";
// }
// int main()
// {
//     int N;
//     cin>>N;
//     int a[N];
//     for(int i = 0 ; i < N ; i++)
//     cin>>a[i];
//     repeat_missing(a,N);
//     return 0;
// }