
                        // Haep Sort 

// Heap sort is based on selection sort but in heao sort we use Mxheap to find largest element to decrease time complexity to nlogn

// Step1 
// Build a MaxHeap 
// Step 2
// Sice root stores maximum element swap root with last element reduce heap size by 1 and heapify root
// Repeat this process untill heap becomes empty

// Time O(nlogn) in all cases          Space O(1)     but in speed  Merge Sort && Quick Sort > Heap Sort
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void Maxheapify(int a[],int N,int i)
{
    int MAX = i,left = 2*i+1,right = 2*i+2;
    if(left < N && a[left] > a[MAX])
    MAX = left;
    if(right < N && a[right] > a[MAX])
    MAX = right;
    if(MAX != i)
    {
        swap(a[i],a[MAX]);
        Maxheapify(a,N,MAX);
    }
}
void build_heap(int a[],int N)
{
    for (int i = (N-2)/2 ; i >= 0; i--)
    Maxheapify(a,N,i);
}
void heap_sort(int a[],int N)
{
    build_heap(a,N);
    for (int i = N - 1; i > 0; i--)
    {
        swap(a[0],a[i]);
        Maxheapify(a,i,0);
    }
}
int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    cin>>a[i];
    heap_sort(a,N);
    for (int i = 0; i < N; i++)
    cout<<a[i]<<" ";
    return 0;
}