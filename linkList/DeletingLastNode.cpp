#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
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

void display()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<"->"<<ptr->data;
        ptr=ptr->next;
    }
}

void deleteLast()
{
    node *ptr = head;
    node *prev = ptr;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next = NULL;
    delete ptr;
    
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    deleteLast();
    cout<<endl<<"After Deleting node in last"<<endl;
    display();
    return 0;
}