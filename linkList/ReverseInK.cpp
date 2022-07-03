#include<iostream>
using namespace std;

class node{
    public:
    node *next;
    int data;
};
node *head;

void insert(int x)
{
    node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    if(head==NULL)
    head = new_node;
    else
    {
        node *ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }
}

void reverse(int k)
{
    node *prev=NULL;
    node *next=NULL;
    node *current=head;
    int c=0;
    while(current != NULL  && c<k)
    {
        next = current->next;
        current->next = prev;
        prev=current;
        current =next;
        c++;
    }
    head = prev;
}

void display()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<"->"<<ptr->data;
        ptr=ptr->next;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    int k;
    cout<<endl<<"Enter the value of k : ";
    cin >> k;
    reverse(k);
    cout<<endl<<"Reverse Linked List : ";
    display();
    return 0;
}