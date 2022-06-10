
// Implement Queue Using Arrays 
// Here we use Circular Array 

#include<iostream>
using namespace std;
class Queue{
    public:
    int *arr;
    int cap;
    int top;
    int start;
    int rear;
    Queue(int c)
    {
        cap = c;
        arr = new int[c];
        top = 0;
        start = 0;
        rear = 0;
    }
    bool isempty()
    {
        return top == 0;
    }
    int size()
    {
        return top;
    }
    void push(int x)
    {
        if(top == cap)
        {
            cout<<"Queue is already full";
        }
        else{
        top++;
        arr[rear] = x;
        rear = (rear+1)%cap;
        }
    }
    void pop()
    {
        if(top == 0)
        {
            cout<<"Queue is already empyt\n";
        }
        else{
        top--;
        start = (start+1)%cap;
        }
    }
    int front()
    {
        if(top == 0)
        {
            cout<<"Queue is already empyt\n";
            return -1;
        }
        else
        return arr[start];
    }
};
int main()
{
    Queue q(5);
    q.push(4);
    q.push(3);
    cout<<q.front()<<"\n";
    q.pop();
    q.pop();
    cout<<q.front()<<"\n";
    q.pop();
    cout<<q.isempty()<<"\n";
    q.push(7);
    cout<<q.size()<<"\n";
    return 0;
}