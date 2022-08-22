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

void middleNode()
{
    int count =0;
    node *ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    ptr=head;
    int position;
    if(count %2 == 0)
    position = count/2;
    else
    position = count/2 +1;
    for(int i=1;i<position;i++)
    {
        ptr = ptr->next;
    }
    cout << ptr->data;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    cout << endl;
    middleNode();
    return 0;
}