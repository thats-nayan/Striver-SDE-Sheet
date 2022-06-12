
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force 
//Traverse over all pairs and store their sum in a vector and find C largest elements using priority queue
// Time O(N*N + NlogN)                 Space O(N*N) 

// Efficient Approach (New Variation)
// If we sort and reverse both arrays 
// Largest sum = {0,0}  Second largest = max({0,1},{1,0})   
// To get naxt greater element we have to any one index of A or B 
// So we mantain a priority queue of {sum,index in 1st array,index in 2nd array} and Do Normal BFS 
// Since indexes arev overlapping we maintain a set of pairs 

void max_sum(int A[],int B[],int N,int C)
{
    sort(A,A+N);
    reverse(A,A+N);
    sort(B,B+N);
    reverse(B,B+N);
    set <pair<int,int>> s;
    priority_queue <vector<int>> pq;
    vector <int> ans;
    pq.push({A[0]+B[0],0,0});
    s.insert({0,0});
    int i = 0;
    while(i < C)
    {
        vector <int> p = pq.top();
        // cout<<"sum = "<<p[0]<<" "<<" i = "<<p[1]<<" j = "<<p[2]<<"\n";
        ans.push_back(p[0]);
        pq.pop();
        if(s.find({p[1]+1,p[2]}) == s.end())
        {
            s.insert({p[1]+1,p[2]});
            pq.push({A[p[1]+1]+B[p[2]],p[1]+1,p[2]});
        }   
        if(s.find({p[1],p[2]+1}) == s.end())
        {
            s.insert({p[1],p[2]+1});
            pq.push({A[p[1]]+B[p[2]+1],p[1],p[2]+1});
        }   
        i++;
    }
    for(auto x: ans)
    cout<<x<<" ";
}
int main()
{
    int N;
    cin>>N;
    int A[N],B[N];
    for (int i = 0; i < N; i++)
    cin>>A[i];
    for (int i = 0; i < N; i++)
    cin>>B[i];
    int C;
    cin>>C;
    max_sum(A,B,N,C);
    return 0;
}