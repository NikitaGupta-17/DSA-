#include<iostream>
using namespace std;

class node
{
    public :
    int data;
    node* next;
    node* previous;
};
node* head;

void insert(int x)
{
    node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    new_node->previous = NULL;
    if(head==NULL)
    {
        new_node->next=head;
       head = new_node;
    }
    else
    {
        node *ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->previous=ptr;
    }
}

void insertatstart(int x)
{
    node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    new_node->previous = NULL;
    new_node->next=head;
    head->previous=new_node;
    head = new_node;
}

void display()
{
    node*ptr =head;
    while(ptr!=NULL)
    {
        cout<<"<=>"<<ptr->data;
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
    insertatstart(5);
    cout << endl << "After adding at start : "<<endl;
    display();
    return 0;
}