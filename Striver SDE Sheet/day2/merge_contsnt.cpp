
// Brute Force 

// Use extra array and merge function of merge sort
// Time O(m+n)                          Space O(m+n) 

// Without Extra Space 

// 1) Insertion sort                        Time O(m*n)       Space O(1)
// Traverse first array and If first element of second array is greater than curr element then swap and sortr second array using insertion sort  

// // Efficient Approach 
// Gap Method 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// void merge(int a[],int b[],int n,int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if(a[i] > b[0])
//         {
//             swap(a[i],b[0]);
//             for (int j = 0; j < m-1; j++)
//             if(b[j+1] < b[j])
//             swap(b[j],b[j+1]);
//         }
//     }
// }
// void merge(int a[],int b[],int n,int m)
// {
//     int x = (n+m)/2 + (n+m)%2;
//     while(x)
//     {
//         int i = 0,j = x;
//         while(j < n+m)
//         {
//             if(j >= n)
//             {
//                 if(i >= n)
//                 {
//                     if(b[i-n] > b[j-n])
//                     {
//                         // cout<<" swap "<<b[i-n]<<" "<<b[j-n]<<"\n";
//                         swap(b[i-n],b[j-n]);
//                     }
//                 }
//                 else
//                 {
//                     if(a[i] > b[j-n])
//                     {
//                         // cout<<" swap "<<a[i]<<" "<<b[j-n]<<"\n";
//                         swap(a[i],b[j-n]);
//                     }
//                 }
//             }
//             else
//             {
//                 if(a[i] > a[j])
//                 {
//                     // cout<<"swap "<<a[i]<<" "<<a[j]<<"\n";
//                     swap(a[i],a[j]);
//                 }
//             }
//             i++;
//             j++;
//         }
//         if(x > 1)
//         x = x/2 + x%2;
//         else
//         x /= 2;
//     }
// }
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     int a[n],b[m];
//     for (int i = 0; i < n; i++)
//     cin>>a[i];
//     for (int j = 0; j < m; j++)
//     cin>>b[j];
//     merge(a,b,n,m);
//     for (int i = 0; i < n; i++)
//     cout<<a[i]<<" ";
//     cout<<"\n";
//     for (int j = 0; j < m; j++)
//     cout<<b[j]<<" ";
//     cout<<"\n";
//     return 0;
// }
