#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};
node* head;
node* head1;

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

void insert1(int x)
{
    node *new_node1 = new node();
    new_node1->data = x;
    new_node1->next = NULL;
    if(head1==NULL)
    head1 = new_node1;
    else
    {
        node *ptr1=head1;
        while(ptr1->next!=NULL)
        {
            ptr1=ptr1->next;
        }
        ptr1->next=new_node1;
    }
}


int compare()
{
    node *ptr=head;
    node *ptr1 = head1;
    int count=0,counter=0;
    while(ptr!=NULL && ptr1!=NULL)
    {
        if(ptr->data == ptr1->data)
        count++;
        ptr=ptr->next;
        ptr1=ptr1->next;
    }
    ptr = head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        counter++;
    }
    if(count == counter)
    return 1;
    else
    return 0;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert1(1);
    insert1(2);
    insert1(3);
    insert1(4);
    if(compare())
    cout<<"IDENTICAL";
    else
    cout << "NOT IDENTICAL";
    return 0;
} 