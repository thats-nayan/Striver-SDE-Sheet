
                    // Combinations Sum 

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// // When we trverase a element we have 2 choices pic element or dont pick 
// void recursion(int a[],int N,int sum,vector <int> temp,vector <vector<int>> &ans)
// {
//     if(sum == 0)
//     ans.push_back(temp);
//     else if(N == 0)
//     return ;
//     else
//     {
//         recursion(a,N-1,sum,temp,ans);
//         if(sum >= a[N-1])
//         {
//             temp.push_back(a[N-1]);
//             recursion(a,N,sum-a[N-1],temp,ans);
//         }
//     }
// }
// vector <vector<int>> combo1(int a[],int N,int sum)
// {
//     vector <vector<int>> ans;
//     vector <int> temp;
//     recursion(a,N,sum,temp,ans);
//     return ans;
// }
// int main()
// {
//     int N,sum;
//     cin>>N>>sum;
//     int a[N];
//     for (int i = 0; i < N; i++)
//     cin>>a[i];
//     vector <vector<int>> ans = combo1(a,N,sum);
//     for(auto x: ans)
//     {
//         for(int i = 0 ; i < x.size() ; i++)
//         cout<<x[i]<<" ";
//         cout<<"\n";
//     }
//     return 0;
// }