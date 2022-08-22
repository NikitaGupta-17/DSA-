#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};
node* head;

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

void NthNode(int N)
{
    node *ptr = head;
    int count = 0,counter=0;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        count++;
    }
    node *ptr1 = head;
    while(counter <= count - N -1)
    {
        ptr1=ptr1->next;
        counter++;
    }
    cout << ptr1->data;
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

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    int N;
    cout << "\nEnter the value of N from last : ";
    cin >> N;
    NthNode(N);
    return 0;
} 