
// Find Pow(x,n) where x is double n is integer 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Ask interviewes if value of n can be negative
// Brute Force Aproach 
// Multipy x to 1 n times 
// Time O(N) 

// Efficient Approach 
// Use Binary Exponentiation 
// Time O(log(N)) 
// Edge case When n = -2^31  then after negation it is overflow error so use long long n instead of n 
double POW(double x,int n)
{
    if(n == 0)
    return 1;
    else if(n < 0)
    return 1/POW(x,-n);
    else
    {
        double res= 1;
        while (n)
        {
            if(n&1)
            res *= x;
            x *= x;
            n/=2;
        }
        return res;
    }
}
int main()
{
    double x;
    int n;
    cin>>x;
    cin>>n;
    cout<<POW(x,n)<<"\n";
    return 0;
}
