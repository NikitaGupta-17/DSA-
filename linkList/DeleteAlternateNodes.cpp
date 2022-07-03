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

void DeleteAltNodes(int nodes)
{
    int temp=nodes;
    node* ptr = head;
    head = head->next;
    ptr->next=NULL;
    delete ptr;
    node *ptr1 = head;
    node *prev = ptr1;
    if(nodes%2 ==0)
    temp = temp-2;
    else
    temp--;
    while(ptr1->next != NULL)
    {
        node *temp1;
        
        if(temp%2 == 0)
        {
            prev=ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            prev->next = ptr1->next;   //1-> 2-> 3-> 4-> 5 (to point 1 to 3)
            temp1 = ptr1;   //a new pointer equal to ptr1 so that we can shift ptr1 to next
            ptr1 = ptr1->next;
            temp1->next = NULL;
            delete temp1; //free the space
        }
        temp--;
    }
    if(nodes%2 != 0){
        prev->next=ptr1->next;
        ptr1->next=NULL;
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

int main()
{
    int i,nodes,num;
    cout<< "Enter the total number of nodes : ";
    cin >> nodes;
    for(i=0;i<nodes;i++)
    {
        cout<<"Enter Node : ";
        cin>>num;
        insert(num);
    }
    display();
    cout<<endl;
    DeleteAltNodes(nodes);
    display();
    return 0;
} 