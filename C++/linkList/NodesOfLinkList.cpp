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

int counter()
{
    node *ptr=head;
    int count = 0;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        count++;
    }
    return count;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    cout<< "Number of nodes present : "<<counter();
    return 0;
} 