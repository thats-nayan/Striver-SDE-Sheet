
// Implement Stack Using Arrays (Vector)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// class Stack
// {
//     public :
//     vector <int> v;
//     int z;
//     Stack()
//     {
//         z = 0;
//     }
//     void push(int x)
//     {
//         v.push_back(x);
//         z++;
//     }
//     void pop()
//     {
//         if(z == 0)
//         cout<<"Stack already empty\n";
//         else{
//         z--;
//         v.pop_back();
//         }
//     }
//     int top()
//     {
//         if(z == 0)
//         {
//             cout<<"Stack is empty\n";
//             return -1;
//         }
//         else
//         return v[z-1];;
//     }
//     bool isempty()
//     {
//         return (z == 0);
//     }   
//     int size()
//     {
//         return z;
//     }
// };
// Stack Implementation Using Linked Lists 
// struct Node
// {
//     int data;
//     Node *next;  
//     Node(int x)
//     {
//         data = x;
//         next = NULL;
//     }
// };
// class Stack
// {
//     public:
//     Node *head;
//     int z ;
//     Stack()
//     {
//         z = 0;
//         head = NULL;
//     }
//     void push(int x)
//     {
//         Node *temp = new Node(x);
//         if(head == NULL)
//         head = temp;
//         else
//         {
//             temp->next = head;
//             head = temp;
//         }
//         z++;
//     }
//     void pop()
//     {
//         if(head == NULL)
//         {
//             cout<<"Stack is already empty\n";
//         }
//         else
//         {
//             Node *temp = head;
//             head = temp->next;
//             z--;
//             delete temp;
//         }
//     }
//     int top()
//     {
//         if(head == NULL)
//         {
//             cout<<"Stack is empty";
//             return -1;
//         }
//         else
//         return head->data;
//     }
//     bool isempty()
//     {
//         return head == NULL;
//     }
//     int size()
//     {
//         return z;
//     }
// };
// int main()
// {
//     Stack s;
//     s.push(4);
//     s.push(5);
//     s.pop();
//     cout<<s.top()<<"\n";
//     s.push(2);
//     cout<<s.size()<<"\n";
//     s.pop();
//     s.pop();
//     s.pop();
//     cout<<s.isempty()<<"\n";
//     return 0;
// }

                    