
                    // Find Nth Root of M in DEimal 

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// // Time O(10^d * log(M+N) )                    Space O(1) 
// long double nth_root(int N,int M)
// {
//     double l = 1;
//     double r = M;
//     while(r-l > 1e-6)       // If we want answer upto x decimal places use difference as 1e-(x+1)
//     {
//         double m = (l+r)/2;
//         double k = pow(m,N);
//         if(k < M)
//         l = m;
//         else
//         r = m;
//     }
//     return r;
// }
// int main()
// {
    // int N,M;
    // cin>>N>>M;
    // cout<<nth_root(N,M);
//     return 0;
// }