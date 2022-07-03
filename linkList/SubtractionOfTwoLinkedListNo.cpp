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

void subtraction()
{
    node *ptr=head;
    node *ptr1=head1;
    int num=0,num1=0;
    while(ptr != NULL)
    {
        num = num*10 +(ptr->data);
        ptr=ptr->next;
    }
    while(ptr1 != NULL)
    {
        num1 = num1*10 +(ptr1->data);
        ptr1=ptr1->next;
    }
    if(num1>num)
    cout<<"subtracting number represented by 1st linked list from 2nd  = "<<num1-num;
    else
    cout<<"subtracting number represented by 2nd linked list from 1st  = "<<num-num1;
}



int main()
{
    int num,num1,i;
    int temp;
    cout<<"Enter The total Number of nodes in 1st linked list : ";
    cin>>num;
    cout<<"Enter nodes : "<<endl;
    for(i=0;i<num;i++)
    {
        cin >> temp;
        insert(temp);
    }
    cout<<endl<<"Enter The total Number of nodes in 2nd linked list : ";
    cin>>num1;
    cout<<"Enter nodes : "<<endl;
    for(i=0;i<num1;i++)
    {
        cin >> temp;
        insert1(temp);
    }
    subtraction();

    return 0;
} 