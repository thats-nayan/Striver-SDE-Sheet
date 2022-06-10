                    // Majority Element 2  (appeares more than n/3 times)

// Brute Force 
// Same as Majority 1 problem 

// Efficent 
// Variation of Moore Algo 
// There can be maxmimum 2 majority elements 
// so istead of one variable we use 2 variable and theire count
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void majority2(int a[],int N)
{
    long long  n1 = INT64_MAX,n2 = INT64_MAX,c1 = 0,c2 = 0;
    for (int i = 0; i < N; i++)
    {
        if(a[i] == n1)
        c1++;
        else if(a[i] == n2)
        c2++;
        else if(c1 == 0)
        {
            n1 = a[i];
            c1 = 1;
        }
        else if(c2 == 0)
        {
            n2 = a[i];
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1 = 0;
    c2 = 0;
    vector <int> ans;
    for (int i = 0; i < N; i++)
    if(a[i] == n1)
    c1++;
    for (int i = 0; i < N; i++)
    if(a[i] == n2)
    c2++;
    if(c1 > N/3)
    ans.push_back(n1);
    if(c2 > N/3)
    ans.push_back(n2);
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    majority2(a,N);
    return 0;
}