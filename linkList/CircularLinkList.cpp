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
    if(head==NULL){
        new_node->next = new_node;
        head = new_node;
    }
    else
    {
        node *ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next = new_node;
        new_node->next = head;
    }
}

void insertatstart(int x)
{
    node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    node* ptr = head;
    while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
    new_node->next = head;
    ptr->next = new_node;
    head = new_node;
}

void display()
{
    node *ptr=head;
    // ptr != head : by this condition if we have only one node than it won't be printed
    //ptr->next != head : by this last element will not be printed so we write one cout outside
    while(ptr->next!=head)
    {
        cout<<"->"<<ptr->data;
        ptr=ptr->next;
    }
    cout<<"->"<<ptr->data;
}

void changefirstnodedata()
{
    node* ptr = head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr=ptr->next;
    int node1;
    cout<<endl <<"Enter the value for node1 : ";
    cin >> node1;
    ptr->data=node1;
}

void deletefirstnodedata()
{
    struct node* ptr = head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next = head->next;
    ptr = head;
    head =  head->next;
    delete ptr;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    insertatstart(5);
    cout<<endl<<"After inserting node at start : "<<endl;
    display();
    changefirstnodedata();
    cout << endl <<"After changing node 1 : "<<endl;
    display();
    cout<<endl<<"After deleting node at start : "<<endl;
    deletefirstnodedata();
    display();
    return 0;
}    