
                        // Three Sum 

// Count unique triplets with sum zero 
// Brute Force 
// Run 3 nested loops and put all triplets in hash set and return size of hash set 
// Time O(n*n*n log m)                            Space O(m)
// where m is no of unique triplets 

// Efficient Method Use hashing 
// Run a loop and store ecah element with frequency in hash map 
// Then run 2 nested loops and for the 3rd elelent in triplet use frequency of that element in hashmap to count 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int triplets(int a[],int N)
{
    
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    cout<<triplets(a,N);
    return 0;
}