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

void insertatposition(int x,int position)
{
    node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    if(position == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else{
    node *ptr=head;
    ptr=head;
    for(int i=1;i<position-1;i++)
    {
        ptr=ptr->next;
    }
    new_node->next=ptr->next;
    ptr->next=new_node;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    insertatposition(5,4);
    cout<<endl<<"After Adding Node at specify position"<<endl;
    display();
    return 0;
}    