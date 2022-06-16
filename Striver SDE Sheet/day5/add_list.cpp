

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
Node *reverse_LL(Node *head)
{
    Node *prev = NULL,*curr = head,*n;
    while(curr != NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
}
Node *add_list(Node *head1,Node *head2)
{
    head1 = reverse_LL(head1);
    head2 = reverse_LL(head2);
    Node *head = NULL,*curr = NULL;
    Node *curr1 = head1,*curr2 = head2;
    int carry = 0;
    while(curr1 != NULL && curr2 != NULL)
    {
        int x = (curr1->data + curr2->data + carry);
        carry = x/10;
        Node *temp = new Node(x%10);
        if(head == NULL)
        {
            head = temp;
            curr = temp;
        }
        else
        {
            curr->next = temp;
            curr = temp;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    while(curr1 != NULL)
    {
        int x = (curr1->data + carry);
        carry = x/10;
        Node *temp = new Node(x%10);
        curr->next = temp;
        curr = temp;
        curr1 = curr1->next;
    }
    while(curr2 != NULL)
    {
        int x = (curr2->data + carry);
        carry = x/10;
        Node *temp = new Node(x%10);
        curr->next = temp;
        curr = temp;
        curr2 = curr2->next;
    }
    if(carry == 1)
    curr->next = new Node(1);
    head = reverse_LL(head);
    return head;
}
int main()
{
    int N,M,x;
    cin>>N>>M;
    Node *head1 = NULL,*head2 = NULL;
    while(N--)
    {
        cin>>x;
        head1 = insert_end(head1,x);
    }
    while(M--)
    {
        cin>>x;
        head2 = insert_end(head2,x);
    }
    Node *head = add_list(head1,head2);
    print_LL(head);
}