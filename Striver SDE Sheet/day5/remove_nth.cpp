
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void print_LL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
Node *insert_end(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}
Node *remove_node(Node *head,int d)
{
    Node *curr = head;
    int k = d+1;
    while (curr != NULL && k--)
    curr = curr->next;
    if(k == 1)
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
    // cout<<"curr = "<<curr->data<<" k = "<<k<<"\n";
    Node *slow = head;
    while(curr != NULL)
    {
        curr = curr->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}
int main()
{
    int N,d,x;
    cin>>N>>d;
    Node *head = NULL;
    while(N--)
    {
        cin>>x;
        head = insert_end(head,x);
    }
    head = remove_node(head,d);
    print_LL(head);
    return 0;
}