#include<iostream>
using namespace std;

class node{
    public :
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

void detectLoop()
{
    int t=0;
    node *slow=head;
    node *fast=head;
    while((slow!=NULL) && (fast!=NULL) && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
        if(slow == fast)
        {
            cout<<"Loop Exists";
            t=1;
            break;
        }
    }
    if(t==0)
    cout<<endl<<"Loop Doesn't Exists";
}

// void display()
// {
//     node *ptr=head;
//     while(ptr!=NULL)
//     {
//         cout<<"->"<<ptr->data;
//         ptr=ptr->next;
//     }
// }

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    head->next->next->next->next = head->next;//Creating Loop
    // display();
    detectLoop();
    return 0;
}