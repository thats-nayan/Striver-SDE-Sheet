
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MinHeap{
    public:
    vector <int> v;
    int cap;
    MinHeap()
    {
        cap = 0;
    }
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return 2*i+2;
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    // Time O(logn)
    void insert(int x)
    {
        v.push_back(x);
        int in = cap;
        while (in > 0 && v[in] < v[parent(in)])
        {
           swap(v[in],v[parent(in)]); 
           in = parent(in);
        }
        cap++;
    }
    // Time O(logN)             Space O(logN)->O(1)
    void heapify(int i)
    {
        int MIN = i;
        if(left(i) < cap && v[left(i)] < v[MIN])
        MIN = left(i);
        if(right(i) < cap && v[right(i)] < v[MIN])
        MIN = right(i);
        if(v[i] == MIN)
        return ;
        if(MIN != i)
        {
            swap(v[i],v[MIN]);
            heapify(MIN);
        }
    }
    // REmoves minimum element from minheap
    // Swap 0th element with last remove last element and heapify 0th element 
    // Time O(logN)    
    int extract_MIN()
    {
        if(cap == 0)
        return -1;
        if(cap == 1)
        {
            cap--;
            return v[0];
        }
        cap--;
        int x = v[0];
        swap(v[0],v[cap]);
        v.pop_back();
        heapify(0);
        return x;
    }
    // Similar to insert function
    // Time O(logN) 
    void decrease_key(int i,int x)
    {
        v[i] = x;
        while(i > 0 && v[i] < v[parent(i)])
        {
            swap(v[i],v[parent(i)]);
            i = parent(i);
        }
    }
    void deletion(int i)
    {
        decrease_key(i,INT32_MIN);
        extract_MIN();
    }
    // Time O(N)  mathematical proff
    void build_heap()
    {
        for (int i = (cap - 2)/2; i >= 0; i--)
        heapify(i);
    }
    void print()
    {
        for(auto x: v)
        cout<<x<<" ";
        cout<<"\n";
    }
};
int main()
{
    int N,x;
    cin>>N;
    MinHeap Mp;
    // while(N--)
    // {
    //     cin>>x;
    //     Mp.insert(x);
    // }
    vector <int> a(N);
    for (int i = 0; i < N; i++)
    cin>>a[i];
    Mp.v = a;
    Mp.cap = N;
    // Mp.heapify(0);
    // Mp.extract_MIN();
    // Mp.decrease_key(3,10);
    // Mp.print();
    // Mp.deletion(3);
    Mp.build_heap();
    Mp.print();
    return 0;
}