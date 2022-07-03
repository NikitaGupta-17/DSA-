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

void insertmiddle(int x)
{
    node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    int count =0;
    node *ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    ptr=head;
    int position = count/2;
    for(int i=1;i<position;i++)
    {
        ptr=ptr->next;
    }
    new_node->next=ptr->next;
    ptr->next=new_node;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    int k;
    cout<<endl <<"Enter the node to be added in middle : ";
    cin >> k;
    insertmiddle(k);
    cout<<endl<<"After Adding node in middle"<<endl;
    display();
    return 0;
}