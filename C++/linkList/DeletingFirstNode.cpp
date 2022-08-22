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

void deleteFirst()
{
    node *ptr = head;
    head = head->next;
    ptr->next=NULL;
    delete ptr;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    deleteFirst();
    cout<<endl<<"After Deleting node in first"<<endl;
    display();
    return 0;
}